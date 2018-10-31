#ifndef SERVER_PACKAGE_FUNCTION_H
#define SERVER_PACKAGE_FUNCTION_H

// 内置函数
#include "last_insert_id.h"
#include "max.h"
#include "min.h"
#include "avg.h"

typedef struct {

    double (*AVG)();

    int (*LAST_INSERT_ID)();

    int (*MAX)();

    int (*MIN)();

} Function;


#endif