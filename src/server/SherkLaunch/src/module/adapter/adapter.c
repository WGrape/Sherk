#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>
#include <sys/stat.h>
#include <SherkService/mechanism/module/administrator/administrator.h>
#include <SherkService/mechanism/module/variable_master/variable_master.h>
#include <string.h>

void adapt_config();

// 初始化适配器
void adapter_init() {

    adapt_config();
}

// 适配配置
void adapt_config() {

    administrator_method_init_config();

    // 读取所有的配置并赋值到全局变量中
    char *store_plan = (char *) malloc(sizeof(char) * 35); // 不分配内存的话会被释放掉, 将无法保存
    strcpy(store_plan, administrator_method_read_config_string("app.server.layer.sherkStorage.storage_plan"));
    VariableMaster_ConfigDocker config_docker;
    variable_master_init_config(&config_docker);
    config_docker.storage_plan=store_plan;
    variable_master_memory_config(config_docker);

}

