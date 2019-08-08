#ifndef SERVER_SHERK_LINK_VENDOR_PROCESS_POOL_MASTER_WORKER_H
#define SERVER_SHERK_LINK_VENDOR_PROCESS_POOL_MASTER_WORKER_H

#include <SherkLink/src/module/network/network.h>

extern void master_worker_pick_from_process_pool(StructSocketArg socketArg);

extern void master_worker_handle(StructSocketArg socketArg);

#endif

