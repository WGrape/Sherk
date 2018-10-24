#include "../include/object/Server.class.h"
#include "../include/define/errorcode.h"


int clientLaunch(){

    Server server;

    if( serverStartup(server) == OK ){

        printf("成功");
        return 0;
    }

}

