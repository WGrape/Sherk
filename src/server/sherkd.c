#include <stdio.h>
#include <SherkLaunch/src/sherkLaunch.h>
#include <msgpack.h>
#include <stdlib.h>
#include <SherkSupport/src/module/table_traverser/table_traverser.h>
#include <SherkSupport/src/include/const/core.h>

int main() {

    // sherkLaunch_start();

    Struct_Table *struct_table_pointer = table_traverser_simulate_a_table_demo("test_database", "test_table", 1,
                                                                               DATABASE_SUPPORT_ENGINE_TYPE_INNODB,
                                                                               DATABASE_SUPPORT_CHARSET_TYPE_UTF8);

    return 0;
}