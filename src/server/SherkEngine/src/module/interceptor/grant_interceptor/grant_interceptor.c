#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SherkSupport/src/module/maintainer/callback/infoschema_callback/infoschema_callback.h>
#include <SherkService/mechanism/module/variable_master/variable_master.h>
#include <SherkSupport/src/module/maintainer/database_in_disk_maintainer/database_in_disk_maintainer.h>
#include <SherkService/test/module/test_database/test_database.h>

extern Variable_Master_Session_Variables variable_master_session_variables;

// 权限拦截器
// 检查当前用户是否具有继续向下执行的权限


int grant_interceptor_is_able_show(){

    return 0;
}

int grant_interceptor_is_able_use(){

    return 0;
}

int grant_interceptor_is_able_create_database(){

    return 0;
}

int grant_interceptor_is_able_drop_database(){

    return 0;
}

int grant_interceptor_is_able_drop_table(){

    return 0;
}

int grant_interceptor_is_able_create_table(){

    return 0;
}

int grant_interceptor_is_able_delete_table(){

    return 0;
}

int grant_interceptor_is_able_desc(){

    return 0;
}


int grant_interceptor_is_able_desc_field(){

    return 0;
}


int grant_interceptor_is_able_select(){

    return 0;
}

int grant_interceptor_is_able_insert(){

    return 0;
}

int grant_interceptor_is_able_update(){

    return 0;
}


