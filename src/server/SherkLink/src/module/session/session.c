#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <SherkService/system/include/const/log_level.h>
#include <SherkService/system/module/logclerk/logclerk.h>
#include <SherkLink/src/module/network/network.h>
#include <SherkService/mechanism/module/variable_master/variable_master.h>
#include <SherkService/mechanism/module/grocery/grocery.h>

void session_manage(StructSocketArg *structSocketArg){

    // 记录下客户端的信息
    VariableMaster_UserClient user_client;
    variable_master_init_client(&user_client);
    user_client.ip = structSocketArg->ip;
    user_client.port = structSocketArg->port;
    user_client.is_login = 1;
    user_client.time = grocery_time_get_now();
    user_client.session = grocery_get_random_md5_string();
    variable_master_memory_client(user_client);

    char log[100];
    memset(log, '\0', sizeof(char) * 100);
    sprintf(log, "client IP:%s, PORT:%d \n", user_client.ip, user_client.port);
    logclerk_write(LOGCLERK_LOG_LEVEL_ACCESS, log);
}



