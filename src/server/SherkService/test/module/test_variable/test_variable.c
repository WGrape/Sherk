#include <stdio.h>
#include <string.h>
#include <SherkSQL/src/module/parser/parser.h>
#include <SherkService/mechanism/module/variable_master/variable_master.h>
#include <SherkService/mechanism/module/administrator/administrator.h>
#include <SherkService/mechanism/module/grocery/grocery.h>

extern Variable_Master_Session_Variables variable_master_session_variables;

// 是否开启了网络调试
int test_variable_is_open() {

    if (0 == grocery_is_debug()) {

        return 0;
    }

    if (1 != administrator_method_read_config_int("app.debug.variable")) {

        return 0;
    }

    return 1;
}

void test_variable_print_variable() {

    VariableMaster_SQLContainer *sql_container_pointer = &(variable_master_session_variables.sql_container);
    VariableMaster_UserClient *user_client_pointer = &(variable_master_session_variables.user_client);

    if (0 == test_variable_is_open()) {

        return;
    }

    // 只有在调试模式下打印
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("| Debug: The information about Variable \n");
    printf("--------------------------------------------------\n");
    printf("| environment  | debug \n");
    printf("| ip           | %s \n", user_client_pointer->ip);
    printf("| port         | %d \n", user_client_pointer->port);
    printf("| name         | %s \n", user_client_pointer->name);
    printf("| password     | %s \n", user_client_pointer->password);
    printf("| is_login     | %d \n", user_client_pointer->is_login);
    printf("| session      | %s \n", user_client_pointer->session);
    printf("| time         | %s \n", user_client_pointer->time);

    printf("| sql          | %s \n", sql_container_pointer->sql);
    printf("| sql_category | %d \n", sql_container_pointer->sql_category);
    if (SQL_CATEGORY_IS_SHERK_COMMAND == sql_container_pointer->sql_category) {

        printf("| command      | %s \n", sql_container_pointer->command);
    }
    printf("| sql_len      | %zd \n", sql_container_pointer->sql_len);
    // printf("| last_sql     | %s \n", sql_container_pointer->last_sql);
    // printf("| last_sql_len | %zd \n", sql_container_pointer->last_sql_len);

    printf("--------------------------------------------------\n");

}



