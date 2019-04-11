#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <include/helper/exit.h>
#include <include/define/const.h>
#include "include/define/rescode.h"
#include "include/define/message.h"

void network_init();
void network_set_server_address(struct sockaddr_in *server_address);


// 网络模块
int GLOBAL_CLIENT_MODULE_NETWORK_conn = -1;
int GLOBAL_CLIENT_MODULE_NETWORK_client_socket = -1;

// 连接
void network_socket_connect(char *sql, char *buffer) {

    network_init();

    int conn = GLOBAL_CLIENT_MODULE_NETWORK_conn, client_socket = GLOBAL_CLIENT_MODULE_NETWORK_client_socket;

    // send the message
    if (RES_EXCEPTION == send(client_socket, sql, strlen(sql), 0)) {

        printf("发送server消息失败...\n");
        return;
    }

    // receive data from the server
    if (RES_EXCEPTION == recv(client_socket, buffer, CONST_BUFFER_SIZE, 0)) {

        printf("接收server响应失败...");
        return;
    }
}

void network_init() {

    if (-1 != GLOBAL_CLIENT_MODULE_NETWORK_conn && -1 != GLOBAL_CLIENT_MODULE_NETWORK_client_socket) {

        return;
    }

    // create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0); // 0表示使用默认的 TCP 协议

    // specify an address for the socket
    struct sockaddr_in server_address;
    network_set_server_address(&server_address);

    //check for error with the connection
    int conn = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (RES_OK != conn) {

        exit_with_error(MES_CLIENT_CANNOT_CONNECT_TO_SERVER);
    }

    // printf("客户端连接服务器成功\n");

    GLOBAL_CLIENT_MODULE_NETWORK_conn = conn;
    GLOBAL_CLIENT_MODULE_NETWORK_client_socket = client_socket;
}

void network_set_server_address(struct sockaddr_in *server_address) {

    server_address->sin_family = AF_INET;
    server_address->sin_port = htons(7834); // 端口号小于1000为系统预留端口 应改为1000以上
    server_address->sin_addr.s_addr = INADDR_ANY; // 对于 windows: 服务端不能使用INADDR_ANY,必须是一个明确的 IP 地址
}