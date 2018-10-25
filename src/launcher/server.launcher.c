#include "../include/object/Server.class.h"
#include "../include/define/errorcode.h"
#include "../include/readConfig/readConfig.h"

int clientLaunch(){

    Server server;

    if( serverStartup(server) == OK ){

        printf("成功");
        return 0;
    }

}

