#include "../include/object/Client.class.h"
#include "../include/object/panel.class.h"
#include "../include/define/errorcode.h"

int clientLaunch(){

    Client client;
    Panel panel;

    if( clientStartup(client) == OK ){

        printf("成功");
        return 0;
    }

}

