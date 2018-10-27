#ifndef OBJECT_CLIENT
#define OBJECT_CLIENT

typedef struct Client {

    ClientPanel clientPanel;

} Client;

extern int client_startup(Client client);

extern int client_shutdown(Client client);

#endif