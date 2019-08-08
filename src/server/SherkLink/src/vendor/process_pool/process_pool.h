#ifndef SERVER_SHERK_LINK_VENDOR_PROCESS_POOL_H
#define SERVER_SHERK_LINK_VENDOR_PROCESS_POOL_H

#include <ntsid.h>

// 参考 : https://blog.csdn.net/stayneckwind2/article/details/61939776
// 参考 : https://blog.csdn.net/stayneckwind2/article/details/61939776

typedef struct process {

    int status; // 进程的状态
    char name[100];
    pid_t pid;
} Struct_Process;

extern void process_pool_test();

extern void process_pool_init();

typedef struct process_pool {

    int status; // 进程池的状态
    int process_num; // 进程数
    int max_process_num; // 最大进程数

    Struct_Process *struct_process_pointer[10];
} Struct_Process_Pool;


#endif
