#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SherkSupport/src/module/maintainer/callback/infoschema_callback/infoschema_callback.h>
#include <SherkService/mechanism/module/variable_master/variable_master.h>
#include <SherkSupport/src/module/maintainer/database_in_disk_maintainer/database_in_disk_maintainer.h>
#include <SherkService/test/module/test_database/test_database.h>

extern Variable_Master_Session_Variables variable_master_session_variables;

// 主拦截器

/**
 * 主拦截器
 * 是否可以放行, 可以放行说明没有发现非法禁止的行为, 不能放行说明拦截到了非法禁止的行为
 * @return 0 表示可以放行, 其他均表示无法放行(不同的值代表不同的原因)
 */
int main_interceptor_is_release(int (*interceptor)()) {

    return interceptor();
}
