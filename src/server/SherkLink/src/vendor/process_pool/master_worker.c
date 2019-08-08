#include <stdio.h>
#include <SherkLink/src/module/network/network.h>
#include "process_pool.h"

extern const int PROCESS_POOL_STATUS_ACTIVE;
extern const int PROCESS_POOL_STATUS_SLEEP;

extern const int PROCESS_STATUS_BUSY;
extern const int PROCESS_STATUS_IDLE;

extern const int process_pool_max_process_num;

extern Struct_Process_Pool process_pool; // 全局变量:进程池

/**
 * 主进程从进程池中挑选进程去处理
 * @return
 */
void master_worker_pick_from_process_pool(StructSocketArg socketArg) {

    // 如果全部都用完的话, 就要求客户端等待
    process_pool_init();
    // process_pool_test();

    // 基于文件来做到子进程和父进程之间的通信
    int pick_success = 0;
    for (int i = 0; i <= process_pool.process_num - 1; ++i) {

        if (0 == pick_success && 0 == process_pool.struct_process_pointer[i]->pid) {

            // 如果没有选中且当前进程空闲
            if (PROCESS_STATUS_IDLE == process_pool.struct_process_pointer[i]->status) {

                // 子进程修改一个全局变量，父进程的这个全局变量不会改变，因为是一个副本, 所以必须用其他方法通信, 我使用基于文件方法
                // printf("--------i:%d,pick_success:%d------\n", i, pick_success);
                process_pool.struct_process_pointer[i]->status = PROCESS_STATUS_BUSY;
                network_handle_client((void *) &socketArg);
                break;
            }
        }
        pick_success = 1;
    }

}

/**
 * 主进程处理
 * @return
 */
void master_worker_handle(StructSocketArg socketArg) {

    // 主进程从进程池中挑选
    master_worker_pick_from_process_pool(socketArg);
}


