#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <SherkService/mechanism/module/administrator/administrator.h>

const int STORAGE_PLAN_SERIALIZATION =1;

// 挂载存储
int mounter_mount_storage(){

    char *storage_plan = administrator_method_read_config_string("app.server.layer.sherkStorage.storage_plan");

    // 如果文件已经以一种存储方案存在了, 那么此次就不再挂载另一种存储方案

    if(0 == strcmp("serialization", storage_plan)){

        return STORAGE_PLAN_SERIALIZATION;
    }

    return 0;
}

