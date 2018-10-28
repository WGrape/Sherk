#include <stdio.h>
#include "../../include/object/SQLResponseData.h"

// 快递服务模块

// 接收 sql 语句
SQLResponseData express_receive_sql(char *sql){

    return express_transport_sql(sql);
}

// 运输 sql 语句
SQLResponseData express_transport_sql(char *sql){

    SQLResponseData sqlResponseData = {};

    return sqlResponseData;
}


