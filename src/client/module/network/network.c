#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <include/helper/exit.h>
#include "include/define/rescode.h"
#include "include/define/message.h"

// 网络模块


// 连接
void network_socket_connect(char *sql) {

    // create a socket
    int network_socket = socket(AF_INET, SOCK_STREAM, 0); // 0表示使用默认的 TCP 协议

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(7834);

    server_address.sin_addr.s_addr = INADDR_ANY; // 对于 windows: 服务端不能使用INADDR_ANY,必须是一个明确的 IP 地址
    // server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // windwos:客户端和服务端都得改,不能只改服务端

    //check for error with the connection
    int conn = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (RES_OK != conn) {

        exit_with_error(MES_CLIENT_CANNOT_CONNECT_TO_SERVER);
    }

    // receive data from the server
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);

    // send the message
    send(conn, sql, sizeof(sql), 0);

    // print out the server's response
    printf("The server send the data : %s\n", server_response);
}



