#include <stdio.h>
#include "process_pool.h"
#include <unistd.h>
#include <stdlib.h>
#include <SherkService/mechanism/module/administrator/administrator.h>

// 进程池状态: 默认是 sleep
const int PROCESS_POOL_STATUS_ACTIVE = 1;
const int PROCESS_POOL_STATUS_SLEEP = 2;

// 进程的状态
const int PROCESS_STATUS_BUSY = 1;
const int PROCESS_STATUS_IDLE = 2;

const int process_pool_max_process_num = 10; // 最大进程数

int process_pool_status = 0;

Struct_Process_Pool process_pool; // 全局变量:进程池

/**
 * 测试进程池
 */
void process_pool_test() {

    int i;
    for (i = 0; i <= process_pool.process_num - 1; ++i) {

        if (0 == process_pool.struct_process_pointer[i]->pid) {

            printf("-----第 %d 个进程,pid:%d-----\n", i, getpid());
        }
    }
}

/**
 * 创建 x 个进程
 * @param x
 */
void process_pool_create_x_process(int x) {

    int i, pid;

    process_pool.max_process_num = process_pool_max_process_num;
    process_pool.process_num = x;

    for (i = 0; i <= x - 1; ++i) {

        process_pool.struct_process_pointer[i] = (Struct_Process *) malloc(sizeof(Struct_Process) * 1);
        pid = fork();
        process_pool.struct_process_pointer[i]->pid = pid;
        process_pool.struct_process_pointer[i]->status = PROCESS_STATUS_IDLE;
        if (pid == 0) {

            // 去处理吧
            return;
        }
    }
}

/**
 * 初始化进程池
 * @return
 */
void process_pool_init() {

    if (PROCESS_POOL_STATUS_ACTIVE == process_pool_status) {

        return;
    }

    process_pool_status = PROCESS_POOL_STATUS_ACTIVE;
    process_pool.status = PROCESS_POOL_STATUS_ACTIVE;

    // 读取配置的进程数
    int process_num = administrator_method_read_config_int(
            "app.server.layer.sherkLink.process_pool.process_num");

    // 创建10个进程(进程数在配置文件中配置)
    process_pool_create_x_process(process_num);
}


