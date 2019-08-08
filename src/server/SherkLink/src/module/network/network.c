#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <SherkSQL/src/module/parser/parser.h>
#include <arpa/inet.h>
#include <SherkService/mechanism/module/variable_master/variable_master.h>
#include <SherkService/mechanism/include/define/const.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <SherkService/mechanism/include/define/message.h>
#include <SherkService/system/include/const/log_level.h>
#include <SherkService/system/module/logclerk/logclerk.h>
#include <SherkService/mechanism/include/define/rescode.h>
#include <SherkService/test/module/test_network/test_network.h>
#include <SherkLink/src/module/process/process.h>
#include <SherkLink/src/module/session/session.h>
#include <SherkLink/src/vendor/process_pool/master_worker.h>
#include <SherkService/mechanism/module/administrator/administrator.h>
#include "network.h"

extern Variable_Master_Session_Variables variable_master_session_variables;

void network_set_server_address(struct sockaddr_in *server_address) {

    server_address->sin_family = AF_INET;
    server_address->sin_port = htons(7834); // 端口号小于1000为系统预留端口 应改为1000以上
    server_address->sin_addr.s_addr = INADDR_ANY; // 对于 windows: 服务端不能使用INADDR_ANY,必须是一个明确的 IP 地址
}

// 处理客户端请求
void network_handle_client(StructSocketArg *structSocketArg) {

    int conn = structSocketArg->conn;
    int server_socket = structSocketArg->server_socket;

    char response[CONST_RESPONSE_SIZE];
    char buffer[CONST_BUFFER_SIZE];

    int loops = 1;
    while (1) {

        if (loops > 999) {

            break;
        }
        loops++;

        // 缓冲关闭, 实时显示打印信息, 防止输出不显示( 有时候可能造成输出不显示的问题, 故强制关闭缓冲 )
        setbuf(stdout, NULL);

        memset(response, '\0', sizeof(char) * CONST_RESPONSE_SIZE);
        memset(buffer, '\0', sizeof(char) * CONST_BUFFER_SIZE);

        ssize_t readnumber = 0;
        readnumber = recv(conn, buffer, CONST_BUFFER_SIZE, 0);
        if (RES_OK > readnumber) {

            grocery_exit_with_error(MES_SERVER_CANNOT_RECV_FROM_SOCKET);
        } else if (0 == readnumber) {

            // 客户端断开连接
            grocery_exit_with_error(MES_SERVER_CANNOT_CONNECT_TO_SOCKET);
            logclerk_write(LOGCLERK_LOG_LEVEL_DEBUG, "network_handle_client() - 客户端断开了");
        }
        logclerk_write(LOGCLERK_LOG_LEVEL_DEBUG, "network_handle_client() - recv成功");

        // 会话管理: 记录下客户端信息
        session_manage(structSocketArg);

        // 解析请求信息
        long start_point = grocery_time_tostruct()->tm_gmtoff;
        strcpy(response, parser_exec(buffer));
        if (NULL != response && '\n' == response[strlen(response) - 1]) {
            response[strlen(response) - 1] = '\0';
        }
        long end_point = grocery_time_tostruct()->tm_gmtoff;
        logclerk_write_slow_query_log(start_point, end_point); // 慢查询记录

        // printf("-------buffer:%s,strlen:%d", response, strlen(response)); 当Response为空的时候, 不会send, 程序就陷入死循环Bug

        // 打印网络
        // test_network_print_network(structSocketArg->ip, structSocketArg->port, response);

        // 不是 send(conn, response, (size_t) readnumber, 0)
        if (RES_OK > send(conn, response, strlen(response), 0)) {

            grocery_exit_with_error(MES_SERVER_CANNOT_SEND_TO_SOCKET);
        }

        logclerk_write(LOGCLERK_LOG_LEVEL_DEBUG, "network_handle_client() - send成功");
    }

    close(conn);
    close(server_socket); // 先别关闭, 关闭的话暂时无法实现持久通信
}

// 监听客户端
void network_listen_client() {

    // create the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0); // 0表示使用默认的 TCP 协议

    // define the server address
    struct sockaddr_in server_address;
    network_set_server_address(&server_address);
    socklen_t server_address_len = sizeof(server_address);

    // bind the socket to our specified IP and port
    if (RES_OK != bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address))) {

        grocery_exit_with_error(MES_SERVER_CANNOT_BIND_TO_SOCKET);
    }
    logclerk_write(LOGCLERK_LOG_LEVEL_DEBUG, "network_listen_client() - bind成功");

    // listen
    if (RES_OK != listen(server_socket, 5)) {

        grocery_exit_with_error(MES_SERVER_CANNOT_LISTEN_TO_SOCKET);
    }
    logclerk_write(LOGCLERK_LOG_LEVEL_DEBUG, "network_listen_client() - listen成功");

    printf("Welcome ! The sherk server star-up successfully !\n");

    int loops = 0;
    while (1) {

        // 第 N 轮
        if (loops > 999) {

            break;
        }
        loops++;
        printf("The %d th : \n", loops);

        /*char log[100];
        sprintf(log, "network_listen_client() - 进入循环, 第 %d 轮", loops);
        logclerk_write(LOGCLERK_LOG_LEVEL_DEBUG, log);*/

        // accept 从处于 established 状态的连接队列头部取出一个已经完成的连接，如果这个队列没有已经完成的连接，accept()函数就会阻塞，直到取出队列中已完成的用户连接为止
        int conn = accept(server_socket, (struct sockaddr *) &server_address, &server_address_len);
        if (RES_OK > conn) {

            grocery_exit_with_error(MES_SERVER_CANNOT_ACCEPT_TO_SOCKET);
        }

        logclerk_write(LOGCLERK_LOG_LEVEL_DEBUG, "network_listen_client() - accept 成功");

        StructSocketArg socketArg = {conn, server_socket, inet_ntoa(server_address.sin_addr),
                                     ntohs(server_address.sin_port), server_address, server_address_len};

        // 是否开启进程池技术
        int process_pool_enable = administrator_method_read_config_int(
                "app.server.layer.sherkLink.process_pool.enable");
        if (process_pool_enable) {

            // 使用进程池技术, 目前此技术有 Bug
            master_worker_handle(socketArg);
        } else {

            // 进程管理: 进程处理
            process_handle(socketArg);
        }

        // 多线程改成多进程方式:这样变量就不会受影响了 !
        // pthread_t handle_client_thread;
        // pthread_create(&handle_client_thread, NULL, (void *) &network_handle_client, (void *) &socketArg);
    }
}

// 初始化网络模块
void network_init() {

    // 启动监听客户端模块
    network_listen_client();
    // pthread_t listen_client_thread;
    // logclerk_write(LOGCLERK_LOG_LEVEL_DEBUG, "创建 listen_client_thread 线程成功, 此线程将去执行 network_listen_client() 方法");
    // pthread_create(&listen_client_thread, NULL, (void *) &network_listen_client, NULL);
    // pthread_join(listen_client_thread, NULL);
}
