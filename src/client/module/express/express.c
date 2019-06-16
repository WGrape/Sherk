#include <stdio.h>
#include "module/network/network.h"


// 快递服务模块


// 运输 sql 语句
void express_transport_sql(char *sql, char *buffer) {

    // 获取到原始的响应数据
    network_socket_connect(sql, buffer);
}



