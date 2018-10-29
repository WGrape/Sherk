#include <stdio.h>
#include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
#include <winsock2.h>
#include "../../include/define/rescode.h"
#include "../../include/define/message.h"

// 网络模块


// 打开 network
void network_open() {

    // WSA初始化
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
}

// 连接
int network_socket_connect() {

    // create a socket
    int network_socket = socket(AF_INET, SOCK_STREAM, 0); // 0表示使用默认的 TCP 协议

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(7834);

    // server_address.sin_addr.s_addr = INADDR_ANY; // 对于 windows: 服务端不能使用INADDR_ANY,必须是一个明确的 IP 地址
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // windwos:客户端和服务端都得改,不能只改服务端

    //check for error with the connection
    if (RES_OK != connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address))) {

        printf("%s : %d \n\n", MES_CLIENT_CANNOT_CONNECT_TO_SERVER, WSAGetLastError());
        return 1;
    }

    // receive data from the server
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);

    // print out the server's response
    printf("The server send the data : %s\n", server_response);

    return 0;
}

// 关闭 network
void network_close() {

    // and then close the socket
    closesocket(socket);

    // 清理 WSA
    WSACleanup();
}


