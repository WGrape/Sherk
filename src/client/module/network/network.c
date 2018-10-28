#include <stdio.h>

#include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")


// 网络模块

int network_connect() {

    // create a socket
    int network_socket = socket(AF_INET, SOCK_STREAM, 0); // 0表示使用默认的 TCP 协议

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(network_socket, (struct sockaddr*) &server_address, sizeof(server_address) );

    //check for error with the connection
    if(connection_status == -1){

        printf("There was an error making a connection to the remote socket \n\n");
    }

    // receive data from the server
    char server_response[256];
    recv(network_socket,&server_response, sizeof(server_response),0);

    // print out the server's response
    printf("The server send the data : %s\n",server_response);

    // and then close the socket
    closesocket(socket);

    return 0;
}

int network_close() {


}


// 登录
int network_login() {


}

// 退出
int network_logout() {


}
