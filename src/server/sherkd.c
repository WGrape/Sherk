#include <stdio.h>
#include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")


int main(){

    char server_message[256] = "You have reached the server!";

    // create the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0); // 0表示使用默认的 TCP 协议

    // define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to our specified IP and port
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address) );

    listen(server_socket,5);

    int client_socket = accept(server_socket,NULL,NULL);

    // send the message
    send(client_socket,server_message, sizeof(server_message),0);

    // and then close the socket
    closesocket(socket);

    return 0;
}