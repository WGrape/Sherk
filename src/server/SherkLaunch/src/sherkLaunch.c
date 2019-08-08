#include <stdio.h>
#include <libconfig.h>
#include "SherkLink/src/sherkLink.h"

#include "./module/adapter/adapter.h"

// 启动 - 启动层
int sherkLaunch_start(){

    // 初始化适配器
    adapter_init();

    // 激活 链接层
    sherkLink_active();

    return 0;
}





