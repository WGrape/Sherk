#ifndef SERVER_SHERK_LINK_MODULE_NETWORK_H
#define SERVER_SHERK_LINK_MODULE_NETWORK_H

#include <arpa/inet.h>

typedef struct StructSocketArg {

    int conn;
    int server_socket;
    char *ip; // 客户端ip
    int port; // 客户端端口
    struct sockaddr_in server_address;
    socklen_t server_address_len;

} StructSocketArg;

extern void network_init();

extern void network_handle_client(StructSocketArg *structSocketArg);


#endif
