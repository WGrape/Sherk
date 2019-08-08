#include <stdio.h>
#include <string.h>
#include <SherkSupport/src/module/maintainer/callback/infoschema_callback/infoschema_callback.h>
#include <SherkService/mechanism/module/variable_master/variable_master.h>
#include <SherkSupport/src/module/maintainer/table_in_memory_maintainer/table_in_memory_maintainer.h>
#include <SherkSupport/src/module/maintainer/table_in_disk_maintainer/table_in_disk_maintainer.h>
#include <SherkService/test/module/test_table/test_table.h>
#include <SherkSupport/src/module/skeleton/skeleton.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <SherkSQL/src/module/analyst/analyst.h>
#include <stdlib.h>
#include <SherkService/test/module/test_users/test_users.h>


extern Variable_Master_Session_Variables variable_master_session_variables;

// private: 获取当前所在的数据库
char *table_servlet_get_databasename() {

    return variable_master_session_variables.database_vessel.database_name;
}

/**
 * Servlet: show tables
 */
int table_servlet_show_tables() {

    char *databasename = table_servlet_get_databasename();

    if (NULL == databasename) {

        return 1;
    }

    test_table_print_tables(databasename);

    return 0;
}

/**
 * Servlet: desc table
 * @param table_name
 */
int table_servlet_desc_table(char *table_name) {

    // 判断是否已选择数据库
    char *database_name = table_servlet_get_databasename();
    if (NULL == database_name) {

        return 1;
    }

    // 数据表不存在
    char *file = grocery_concat_table_location_string(database_name, table_name);
    if (0 == grocery_is_file_exists(file)) {

        return 2;
    }

    file = grocery_concat_table_frm_location_string(database_name, table_name);
    table_in_disk_maintainer_desc_table(file);

    return 0;
}

/**
 * Servlet: desc table field
 * @param table_name
 */
int table_servlet_desc_table_field(char *table_name) {

    // 判断是否已选择数据库
    char *database_name = table_servlet_get_databasename();
    if (NULL == database_name) {

        return 1;
    }

    // 数据表不存在
    char *file = grocery_concat_table_location_string(database_name, table_name);
    if (0 == grocery_is_file_exists(file)) {

        return 2;
    }

    // 数据表字段文件
    file = grocery_concat_table_field_location_string(database_name, table_name);
    table_in_disk_maintainer_desc_table_field(file);

    return 0;
}

/**
 * Servlet: select table
 * @param table_name
 * @return
 */
int table_servlet_select_table(char *table_name) {

    // 判断是否已选择数据库
    char *database_name = table_servlet_get_databasename();
    if (NULL == database_name) {

        return 1;
    }

    // 数据表不存在
    char *file = grocery_concat_table_location_string(database_name, table_name);
    if (0 == grocery_is_file_exists(file)) {

        return 2;
    }

    Struct_Table *struct_table_pointer = table_in_disk_maintainer_select_table(database_name, table_name);
    test_table_print_table_info(struct_table_pointer);

    return 0;
}

/**
 * Servlet: select part table
 * @param table_name
 * @return
 */
int table_servlet_select_table_part(char *table_name) {

    // 判断是否已选择数据库
    char *database_name = table_servlet_get_databasename();
    if (NULL == database_name) {

        return 1;
    }

    // 数据表不存在
    char *file = grocery_concat_table_location_string(database_name, table_name);
    if (0 == grocery_is_file_exists(file)) {

        return 2;
    }

    Struct_Table *struct_table_pointer = table_in_disk_maintainer_select_table(database_name, table_name);
    table_in_disk_maintainer_select_table_where_by_id(struct_table_pointer, OPERATOR_EQ, 3);

    return 0;
}

/**
 * Servlet: update table
 * @param table_name
 * @return
 */
int table_servlet_update_table(char *table_name, int field_count, char **field_name_list, int *field_type_list,
                               int *field_value_int,
                               float *field_value_float, char *field_value_char, char **field_value_string,
                               char **condition_name_list, char **condition_operator_list,
                               char **condition_value_list) {

    // 判断是否已选择数据库
    char *database_name = table_servlet_get_databasename();
    if (NULL == database_name) {

        return 1;
    }

    // 数据表不存在
    char *file = grocery_concat_table_location_string(database_name, table_name);
    if (0 == grocery_is_file_exists(file)) {

        return 2;
    }

    int id = atoi(condition_value_list[0]);
    char *column = condition_name_list[0];

    // printf("---id:%d-----column:%s", id, column);

    Struct_Table *struct_table_pointer = table_in_disk_maintainer_select_table(database_name, table_name);
    table_in_memory_maintainer_update_a_record(file, struct_table_pointer, field_count, field_name_list,
                                               field_type_list, field_value_int,
                                               field_value_float, field_value_char,
                                               field_value_string, column, id);

    return 0;
}

/**
 * Servlet: insert table
 * @param table_name
 * @param record
 * @return
 */
int table_servlet_insert_table(char *table_name, char *record) {

    // 判断是否已选择数据库
    char *database_name = table_servlet_get_databasename();
    if (NULL == database_name) {

        return 1;
    }

    // 数据表不存在
    char *file = grocery_concat_table_location_string(database_name, table_name);
    if (0 == grocery_is_file_exists(file)) {

        return 2;
    }

    // printf("----table_name:%s------record:%s-------", table_name, record);
    strcat(record, "\n");
    table_in_disk_maintainer_insert_table(file, record);
    return 0;
}

/**
 * Servlet: drop table
 * @param table_name
 */
void table_servlet_drop_table(char *table_name) {

    char *database_name = table_servlet_get_databasename();

    // Memory 操作: drop table
    table_in_memory_maintainer_drop_table(database_name, table_name, INFOSCHEMA_CALLBACK_ABLE);

    // Dick 操作: drop table
    table_in_disk_maintainer_drop_table(database_name, table_name, INFOSCHEMA_CALLBACK_ABLE);
}

/**
 * Servlet: delete table
 * @param table_name
 */
void table_servlet_delete_table(char *table_name) {

    char *database_name = table_servlet_get_databasename();

    // Memory 操作: drop table
    table_in_memory_maintainer_drop_table(database_name, table_name, INFOSCHEMA_CALLBACK_ABLE);

    // Dick 操作: drop table
    table_in_disk_maintainer_drop_table(database_name, table_name, INFOSCHEMA_CALLBACK_ABLE);
}

void
table_servlet_sys_users_table_generate_record(Struct_Table *struct_table_pointer, int record_index, char *name,
                                              char *password) {

    Struct_Field *first_field_pointer = NULL;
    Struct_Field *last_field_pointer = NULL;
    Struct_Field *current_field_pointer = NULL;

    // 生成 id 字段
    current_field_pointer = table_in_memory_maintainer_create_a_field_int(FIELD_TYPE_INT, "id", record_index, 0, 0, 1);
    first_field_pointer = current_field_pointer;
    last_field_pointer = current_field_pointer;

    // 生成 name 字段
    current_field_pointer = table_in_memory_maintainer_create_a_field_string(FIELD_TYPE_STRING, "name", name, 1, 0, 0);
    table_in_memory_maintainer_append_a_field(last_field_pointer, current_field_pointer);
    last_field_pointer = current_field_pointer;

    // 生成 password 字段
    current_field_pointer = table_in_memory_maintainer_create_a_field_string(FIELD_TYPE_STRING, "password", password,
                                                                             2, 0, 0);
    table_in_memory_maintainer_append_a_field(last_field_pointer, current_field_pointer);
    last_field_pointer = current_field_pointer;


    // 生成 grants 字段( 只有root用户或者lvsi用户, 享有全部权限 )
    char *grants = (0 == strcmp("root", name) || 0 == strcmp("lvsi", name))
                   ? "SHOW,CREATE,DROP,INSERT,DELETE,UPDATE,SELECT" : "CREATE,DROP,INSERT,DELETE,UPDATE,SELECT";
    current_field_pointer = table_in_memory_maintainer_create_a_field_string(FIELD_TYPE_STRING, "grants", grants, 3, 0, 0);
    table_in_memory_maintainer_append_a_field(last_field_pointer, current_field_pointer);
    last_field_pointer = current_field_pointer;


    // 生成 time 字段
    current_field_pointer = table_in_memory_maintainer_create_a_field_string(FIELD_TYPE_STRING, "time",
                                                                             grocery_time_get_now(), 4, 0, 0);
    table_in_memory_maintainer_append_a_field(last_field_pointer, current_field_pointer);


    // 插入记录
    table_in_memory_maintainer_insert_a_record(struct_table_pointer, first_field_pointer);

    // test_table_print_table_record_info(first_field_pointer);
}

void
table_servlet_generate_records(Struct_Table *struct_table_pointer, char **field_name_list, const int *field_type_list,
                               int field_count, int record_count) {

    int i, j;
    Struct_Field *first_field_pointer = NULL;
    Struct_Field *last_field_pointer = NULL;
    Struct_Field *current_field_pointer = NULL;
    for (i = 1; i <= record_count; ++i) {

        for (j = 0; j <= field_count - 1; ++j) {

            if (0 == strcmp("id", field_name_list[j])) {

                current_field_pointer = table_in_memory_maintainer_create_a_field_int(FIELD_TYPE_INT,
                                                                                      field_name_list[j], i, j, 0,
                                                                                      j == 0);
            } else if (FIELD_TYPE_INT == field_type_list[j]) {

                current_field_pointer = table_in_memory_maintainer_create_a_field_int(FIELD_TYPE_INT,
                                                                                      field_name_list[j],
                                                                                      (i % 2 == 0)
                                                                                      ? grocery_get_random_int(1, 10000)
                                                                                      : grocery_get_random_int(50,
                                                                                                               1000),
                                                                                      j, 0,
                                                                                      j == 0);
            } else if (FIELD_TYPE_FLOAT == field_type_list[j]) {

                current_field_pointer = table_in_memory_maintainer_create_a_field_float(FIELD_TYPE_FLOAT,
                                                                                        field_name_list[j], 15.4, j, 0,
                                                                                        j == 0);
            } else if (FIELD_TYPE_CHAR == field_type_list[j]) {

                current_field_pointer = table_in_memory_maintainer_create_a_field_char(FIELD_TYPE_CHAR,
                                                                                       field_name_list[j], 'a', j, 0,
                                                                                       j == 0);
            } else {

                current_field_pointer = table_in_memory_maintainer_create_a_field_string(FIELD_TYPE_STRING,
                                                                                         field_name_list[j],
                                                                                         grocery_get_random_md5_string_6(),
                                                                                         j, 0,
                                                                                         j == 0);
            }

            if (0 == j) {

                first_field_pointer = current_field_pointer;
            } else {

                table_in_memory_maintainer_append_a_field(last_field_pointer, current_field_pointer);
            }

            last_field_pointer = current_field_pointer;
        }

        table_in_memory_maintainer_insert_a_record(struct_table_pointer, first_field_pointer);
    }
}

/**
 * Servlet: create table
 * @param table_name
 * @param field_name_list
 * @param field_type_list
 */
int table_servlet_create_table(char *table_name, char **field_name_list, int *field_type_list, int field_count) {

    // 判断是否已选择数据库
    char *database_name = table_servlet_get_databasename();
    if (NULL == database_name) {

        return 1;
    }

    // 判断数据表是否已存在
    if (table_in_disk_maintainer_table_is_exist(database_name, table_name)) {

        return 3;
    }

    // 创建基本表结构
    Struct_Table *struct_table_pointer = table_in_memory_maintainer_create_a_table(database_name, table_name, 1,
                                                                                   DATABASE_SUPPORT_ENGINE_TYPE_INNODB,
                                                                                   DATABASE_SUPPORT_CHARSET_TYPE_UTF8);
    // 创建表头
    table_in_memory_maintainer_create_table_head(struct_table_pointer, field_name_list, field_type_list, field_count);

    // 为表生成数据
    if (1 == analyst_analysis_sql_is_create_sys_table(table_name)) {

        // 如果是创建系统表, 则自动生成记录, 根据当前的用户来生成记录
        // Drop: table_servlet_generate_records(struct_table_pointer, field_name_list, field_type_list, field_count, 5);
        // 获取 name 数组 和 password 数组
        RES_ARRAY *users_username = test_users_get_users_username();
        RES_ARRAY *users_password = test_users_get_users_password();
        int i, count = users_username->count;
        for (i = 0; i <= count - 1; ++i) {

            table_servlet_sys_users_table_generate_record(struct_table_pointer, i + 1, users_username->array[i],
                                                          users_password->array[i]);
        }
    }

    // 在磁盘上创建表
    table_in_disk_maintainer_create_table(database_name, table_name, struct_table_pointer);

    // 打印表
    test_table_print_table_info(struct_table_pointer);

    return 0;
}


