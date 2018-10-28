#include <stdio.h>

#include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
#include <winsock2.h>


// 网络模块

int network_start(){

    // WSA初始化
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);


    char server_message[256] = "You have reached the server!";

    // create the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0); // 0表示使用默认的 TCP 协议

    // define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(7834); // 端口号小于1000为系统预留端口 应改为1000以上
    // server_address.sin_addr.s_addr = INADDR_ANY; // 对于 windows: 服务端不能使用INADDR_ANY,必须是一个明确的 IP 地址
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // windwos:客户端和服务端都得改,不能只改服务端

    // bind the socket to our specified IP and port
    if( -1 == bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address) ) ){

        printf("Sherk server bind with a socket error : %d\n\n", WSAGetLastError());
        return 0;
    }

    // listen
    if( -1 == listen(server_socket,5) ){

        printf("Sherk server bind with a socket error : %d\n\n", WSAGetLastError());
        return 0;
    }

    int client_socket = accept(server_socket,NULL,NULL);

    // send the message
    send(client_socket,server_message, sizeof(server_message),0);

    // and then close the socket
    closesocket(socket);

    // 清理 WSA
    WSACleanup();

    return 1;
}