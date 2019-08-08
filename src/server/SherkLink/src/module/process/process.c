#include <stdio.h>
#include <unistd.h>
#include <SherkService/system/include/const/log_level.h>
#include <SherkService/system/module/logclerk/logclerk.h>
#include <SherkLink/src/module/network/network.h>

int process_init(){

    return 0;
}

void process_handle(StructSocketArg socketArg){

    pid_t pid = fork();
    if (0 == pid) {

        logclerk_write(LOGCLERK_LOG_LEVEL_DEBUG,"network_listen_client() - 成功创建 pid 进程, 此进程将去执行 network_handle_client() 方法");
        network_handle_client((void *) &socketArg);
    }
}



