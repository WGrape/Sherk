#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SherkService/mechanism/module/variable_master/variable_master.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <SherkEngine/src/module/servlet/database_servlet/database_servlet.h>
#include <SherkEngine/src/module/servlet/table_servlet/table_servlet.h>
#include <SherkEngine/src/module/interceptor/main_interceptor/main_interceptor.h>
#include <SherkService/mechanism/include/define/rescode.h>
#include <SherkEngine/src/module/interceptor/grant_interceptor/grant_interceptor.h>

/**
 * 执行命令: 登录
 * @param name
 * @param password
 * @return
 */
char *executor_handle_command_login(char *name, char *password) {

    // printf("----------name:%s----------\n", name);
    // printf("----------password:%s----------\n", password);

    // 记录 客户端用户的账号和密码 信息
    VariableMaster_UserClient user_client;
    variable_master_init_client(&user_client);
    char *memory_name = (char *) malloc(sizeof(char) * 35); // 不分配内存的话会被释放掉, 将无法保存
    strcpy(memory_name, name);
    user_client.name = memory_name;
    char *memory_password = (char *) malloc(sizeof(char) * 35); // 不分配内存的话会被释放掉, 将无法保存
    strcpy(memory_password, password);
    user_client.password = memory_password;
    variable_master_memory_client(user_client);

    // 记录 SQL 信息
    VariableMaster_SQLContainer sql_container;
    variable_master_init_sql(&sql_container);
    sql_container.command = "login";
    variable_master_memory_sql(sql_container);

}

/**
 * 执行SQL: show databases
 */
void executor_handle_sql_show_databases() {

    int grant = main_interceptor_is_release(grant_interceptor_is_able_show);
    if (RES_OK != grant) {

        // 没有show权限
    }

    // Servlet: show databases
    database_servlet_show_databases();
}

/**
 * 执行SQL: show tables
 */
int executor_handle_sql_show_tables() {

    int grant = main_interceptor_is_release(grant_interceptor_is_able_show);
    if (RES_OK != grant) {

        // 没有show权限
    }

    // Servlet: show databases
    return table_servlet_show_tables();
}

/**
 * 执行SQL: use database
 * @param database_name
 */
void executor_handle_sql_use_database(char *database_name) {

    int grant = main_interceptor_is_release(grant_interceptor_is_able_use);
    if (RES_OK != grant) {

        // 没有use权限
    }

    // Servlet: use database
    database_servlet_use_database(database_name);
}

/**
 * 执行SQL: create database
 * @param database_name
 */
void executor_handle_sql_create_database(char *database_name) {

    int grant = main_interceptor_is_release(grant_interceptor_is_able_create_database);
    if (RES_OK != grant) {

        // 没有create database权限
    }

    // Servlet: create database
    database_servlet_create_database(database_name);
}

/**
 * 执行SQL: drop database
 * @param database_name
 */
void executor_handle_sql_drop_database(char *database_name) {

    int grant = main_interceptor_is_release(grant_interceptor_is_able_drop_database);
    if (RES_OK != grant) {

        // 没drop权限
    }

    // Servlet: drop database
    database_servlet_drop_database(database_name);
}

/**
 * 执行SQL: desc table
 * @param table_name
 */
int executor_handle_sql_desc_table(char *table_name) {

    int grant = main_interceptor_is_release(grant_interceptor_is_able_desc);
    if (RES_OK != grant) {

        // 没desc权限
    }

    // Servlet: desc table
    return table_servlet_desc_table(table_name);
}

/**
 * 执行SQL: desc table field
 * @param table_name
 */
int executor_handle_sql_desc_table_field(char *table_name) {

    int grant = main_interceptor_is_release(grant_interceptor_is_able_desc_field);
    if (RES_OK != grant) {

        // 没desc field权限
    }

    // Servlet: desc table field
    return table_servlet_desc_table_field(table_name);
}

/**
 * 执行SQL: select * from table
 * @param table_name
 * @return
 */
int executor_handle_sql_select_table(char *table_name) {

    int grant = main_interceptor_is_release(grant_interceptor_is_able_select);
    if (RES_OK != grant) {

        // 没select权限
    }

    // Servlet: select table
    return table_servlet_select_table(table_name);
}

/**
 * 执行SQL: select table
 * @param table_name
 * @return
 */
int executor_handle_sql_select_table_part(char *table_name) {

    int grant = main_interceptor_is_release(grant_interceptor_is_able_select);
    if (RES_OK != grant) {

        // 没select权限
    }

    // Servlet: select table
    return table_servlet_select_table_part(table_name);
}

/**
 * 执行SQL: insert table
 * @param table_name
 * @param record
 * @return
 */
int executor_handle_sql_insert_table(char *table_name, char *record) {

    int grant = main_interceptor_is_release(grant_interceptor_is_able_insert);
    if (RES_OK != grant) {

        // 没insert权限
    }

    // Servlet: insert table
    return table_servlet_insert_table(table_name, record);
}

/**
 * 执行SQL: update table
 * @param table_name
 * @param field_count
 * @param field_name_list
 * @param field_type_list
 * @param field_value_int
 * @param field_value_float
 * @param field_value_char
 * @param field_value_string
 * @return
 */
int executor_handle_sql_update_table(char *table_name, int field_count, char **field_name_list, int *field_type_list,
                                     int *field_value_int,
                                     float *field_value_float, char *field_value_char, char **field_value_string,
                                     char **condition_name_list, char **condition_operator_list,
                                     char **condition_value_list) {

    int grant = main_interceptor_is_release(grant_interceptor_is_able_update);
    if (RES_OK != grant) {

        // 没update权限
    }

    // Servlet: update table
    return table_servlet_update_table(table_name, field_count, field_name_list,
                                      field_type_list, field_value_int,
                                      field_value_float, field_value_char,
                                      field_value_string, condition_name_list,
                                      condition_operator_list, condition_value_list);
}

/**
 * 执行SQL: drop table
 * @param table_name
 */
void executor_handle_sql_drop_table(char *table_name) {

    int grant = main_interceptor_is_release(grant_interceptor_is_able_drop_table);
    if (RES_OK != grant) {

        // 没drop table权限
    }

    // Servlet: drop table
    table_servlet_drop_table(table_name);
}

/**
 * 执行SQL: delete table
 * @param table_name
 */
void executor_handle_sql_delete_table(char *table_name) {

    int grant = main_interceptor_is_release(grant_interceptor_is_able_delete_table);
    if (RES_OK != grant) {

        // 没delete table权限
    }

    // Servlet: delete table
    table_servlet_delete_table(table_name);
}

/**
 * 执行SQL: create table
 * @param table_name
 * @param field_name_list
 * @param field_type_list
 */
int executor_handle_sql_create_table(char *table_name, char **field_name_list, int *field_type_list, int field_count) {

    int grant = main_interceptor_is_release(grant_interceptor_is_able_create_table);
    if (RES_OK != grant) {

        // 没create table权限
    }

    // Servlet: create table
    return table_servlet_create_table(table_name, field_name_list, field_type_list, field_count);
}

