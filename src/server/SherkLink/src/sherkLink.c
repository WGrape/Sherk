#include <stdio.h>
#include <SherkLink/src/module/network/network.h>
#include <SherkLink/src/module/process/process.h>

// 激活链接层
int sherkLink_active(){

    // 初始化进程模块
    process_init();

    // 初始化网络模块
    network_init();

    return 0;
}
