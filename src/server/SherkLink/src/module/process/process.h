#ifndef SERVER_SHERK_LINK_MODULE_PROCESS_H
#define SERVER_SHERK_LINK_MODULE_PROCESS_H

#include <SherkLink/src/module/network/network.h>

extern int process_init();

extern void process_handle(StructSocketArg socketArg);

#endif
