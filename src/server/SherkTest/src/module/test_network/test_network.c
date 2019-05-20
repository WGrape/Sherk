#include <stdio.h>
#include <string.h>
#include <SherkMechanism/src/module/administrator/administrator.h>
#include <SherkMechanism/src/module/grocery/grocery.h>
#include <SherkMechanism/src/module/variable_master/variable_master.h>
#include <SherkSQL/src/module/parser/parser.h>

extern Variable_Master_Session_Variables variable_master_session_variables;

// 是否开启了网络调试
int test_network_is_open() {

    if (0 == grocery_is_debug()) {

        return 0;
    }

    if (1 != administrator_method_read_config_int("app.debug.network")) {

        return 0;
    }

    return 1;
}

void test_network_print_network(char *ip, int port, char *response) {

    if (0 == test_network_is_open()) {

        return;
    }

    // 只有在调试模式下打印
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("| Debug: The information about Network \n");
    printf("--------------------------------------------------\n");
    printf("| environment  | debug \n");
    printf("| ip           | %s \n", ip);
    printf("| port         | %d \n", port);
    printf("| sql          | %s \n", variable_master_session_variables.sql_container.sql);
    printf("| sql_category | %d \n", variable_master_session_variables.sql_container.sql_category);

    if (SQL_CATEGORY_IS_SHERK_COMMAND == variable_master_session_variables.sql_container.sql_category) {

        printf("| command      | %s \n", variable_master_session_variables.sql_container.command);
    }

    printf("| sql_len      | %zd \n", variable_master_session_variables.sql_container.sql_len);
    // printf("| last_sql     | %s \n", variable_master_session_variables.sql_container.last_sql);
    // printf("| last_sql_len | %zd \n", variable_master_session_variables.sql_container.last_sql_len);
    printf("| response     | %s \n", response);
    printf("--------------------------------------------------\n");

}


