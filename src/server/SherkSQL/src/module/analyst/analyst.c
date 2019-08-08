#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SherkSQL/src/module/parser/parser.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <SherkSupport/src/module/skeleton/skeleton.h>
#include <SherkService/mechanism/module/variable_master/variable_master.h>
#include <SherkService/test/vendor/faker/faker.h>


// 分析家

extern Variable_Master_Session_Variables variable_master_session_variables;


/**
 * 分析SQL分类
 */
int analyst_analysis_sql_category(char *sql) {

    char *pattern_command = "^\\s*command=.*$";
    char *pattern_sql = "^\\s*sql=.*$";

    if (0 == strcmp("sql=sherk", grocery_string_cutwords(sql, 0, 8))) {

        return SQL_CATEGORY_IS_SHERK_COMMAND_IN_SQL;
    } else if (parser_match_regex(pattern_command, sql)) {

        // 传来的SQL是command
        return SQL_CATEGORY_IS_SHERK_COMMAND;
    } else if (parser_match_regex(pattern_sql, sql)) {

        // 传来的SQL是SQL命令
        return SQL_CATEGORY_IS_SQL;
    } else {

        return -1;
    }
}


char *analyst_analysis_command_login_get_name(char *command) {

    int left = grocery_string_get_str_last_char_index(command, "name=", 1) + 1;
    int right = grocery_string_get_str_first_char_index(command, ", password", 1) - 1;
    char *name = grocery_string_cutwords(command, left, right);

    return name;
}

char *analyst_analysis_command_login_get_password(char *command) {

    char *pos = grocery_string_get_str_next_char_address(command, ", password=", 1);

    return pos;
}

char *analyst_analysis_sql_use_database_get_database_name(char *command) {

    char *pos = grocery_string_get_str_next_not_white_char_address(command, "use ", 1);
    return pos;
}

char *analyst_analysis_sql_create_database_get_database_name(char *command) {

    char *pos = grocery_string_get_str_next_char_address(command, "database ", 1);

    return pos;
}

char *analyst_analysis_sql_drop_table_get_table_name(char *command) {

    char *pos = grocery_string_get_str_next_char_address(command, "table ", 1);

    return pos;
}

char *analyst_analysis_sql_delete_from_table_get_table_name(char *command) {

    char *pos = grocery_string_get_str_next_char_address(command, "from ", 1);

    return pos;
}

char *analyst_analysis_sql_create_table_get_table_name(char *command) {

    if (0 > grocery_string_get_str_first_char_index(command, "(", 0)) {

        char *pos = grocery_string_get_str_next_char_address(command, "table ", 1);
        return pos;
    }

    int left = grocery_string_get_str_last_char_index(command, "table ", 1) + 1;
    int right = grocery_string_get_str_first_char_index(command, "(", 1) - 1;
    return grocery_string_cutwords(command, left, right);
}

char *analyst_analysis_sql_desc_table_get_table_name(char *command) {

    char *pos = grocery_string_get_str_next_char_address(command, "table ", 1);

    return pos;
}

char *analyst_analysis_sql_desc_table_field_get_table_name(char *command) {

    char *pos = grocery_string_get_str_next_char_address(command, "field ", 1);

    return pos;
}

char *analyst_analysis_sql_select_table_get_table_name(char *command) {

    char *pos = grocery_string_get_str_next_char_address(command, "from ", 1);

    return pos;
}

char *analyst_analysis_sql_select_table_part_get_table_name(char *command) {

    char *pos = grocery_string_get_str_next_char_address(command, "table ", 1);

    return pos;
}

char *analyst_analysis_sql_update_table_get_table_name(char *command) {

    int left = grocery_string_get_str_last_char_index(command, "update ", 1) + 1;
    int right = grocery_string_get_str_first_char_index(command, "set", 1) - 1;
    return grocery_string_trim(grocery_string_cutwords(command, left, right));
}

char *analyst_analysis_sql_insert_table_get_table_name(char *command) {

    if (0 > grocery_string_get_str_first_char_index(command, "(", 0)) {

        char *pos = grocery_string_get_str_next_char_address(command, "table ", 1);
        return pos;
    }

    int left = grocery_string_get_str_last_char_index(command, "into ", 1) + 1;
    int right = grocery_string_get_str_first_char_index(command, "(", 1) - 1;
    return grocery_string_cutwords(command, left, right);
}

char *analyst_analysis_sql_insert_table_get_record(char *command) {

    char *table_name = analyst_analysis_sql_insert_table_get_table_name(command);

    return faker_simulate_a_record_json(6, table_name);
}

char *analyst_analysis_sql_insert_table_get_record_update(char *command) {

    char *table_name = analyst_analysis_sql_insert_table_get_table_name(command);

    return faker_simulate_a_record_update_json(6, table_name);
}

/**
 * 分析字段的类型 - 根据 field_type( 字符串类型 )
 * @param field_type
 * @return
 */
int analyst_analysis_field_type_by_field_type_string(char *field_type) {

    if (0 == strcmp("int", field_type)) {

        return FIELD_TYPE_INT;
    }

    if (0 == strcmp("float", field_type)) {

        return FIELD_TYPE_FLOAT;
    }

    if (0 == strcmp("char", field_type)) {

        return FIELD_TYPE_CHAR;
    }

    if (0 == strcmp("string", field_type)) {

        return FIELD_TYPE_STRING;
    }

    return FIELD_TYPE_ERROR;
}

/**
 * 分析字段的类型 - 根据 field_value( 字符串类型 )
 * @return
 */
int analyst_analysis_field_type_by_field_value_string(const char *field_value) {

    if ('\"' == field_value[0]) {

        return FIELD_TYPE_STRING;
    }

    if ('\'' == field_value[0]) {

        return FIELD_TYPE_CHAR;
    }

    if (0 < grocery_string_get_str_first_char_index(field_value, ".", 0)) {

        return FIELD_TYPE_FLOAT;
    }

    return FIELD_TYPE_INT;
}

char **analyst_analysis_sql_create_table_get_field_name_list(char *command) {


    char **field_name_list = (char **) malloc(sizeof(char *) * 4);

    field_name_list[0] = "id";
    field_name_list[1] = "name";
    field_name_list[2] = "age";
    field_name_list[3] = "sex";

    return field_name_list;
}

int *analyst_analysis_sql_create_table_get_field_type_list(char *command) {

    int *field_type_list = (int *) malloc(sizeof(int) * 4);

    field_type_list[0] = FIELD_TYPE_INT;
    field_type_list[1] = FIELD_TYPE_STRING;
    field_type_list[2] = FIELD_TYPE_INT;
    field_type_list[3] = FIELD_TYPE_STRING;

    return field_type_list;
}

int analyst_analysis_sql_is_create_sys_table(char *table_name) {

    // 必须写这个, 必须先判断database是否为空, 否则下面 strcmp 时程序会异常退出
    if (NULL == variable_master_session_variables.database_vessel.database_name) {

        return 0;
    }

    // 先看当前所在 database 是不是 information_schema, 再看表名是不是 users, tables_manage, databases_manage
    if (0 == strcmp("information_schema", variable_master_session_variables.database_vessel.database_name)) {

        if (0 == strcmp("users", table_name)) {

            return 1;
        }

        if (0 == strcmp("tables_manage", table_name)) {

            return 1;
        }

        if (0 == strcmp("databases_manage", table_name)) {

            return 1;
        }
    }

    return 0;
}

char **analyst_analysis_sql_create_sys_table_get_field_name_list(char *command, char *table_name) {

    char **field_name_list = (char **) malloc(sizeof(char *) * 4);
    if (0 == strcmp("databases_manage", table_name)) {

        field_name_list[0] = "id";
        field_name_list[1] = "name";
        field_name_list[2] = "time";
        field_name_list[3] = "encryption";
    } else if (0 == strcmp("tables_manage", table_name)) {

        field_name_list[0] = "id";
        field_name_list[1] = "name";
        field_name_list[2] = "database";
        field_name_list[3] = "time";
    } else if (0 == strcmp("users", table_name)) {

        free(field_name_list);
        field_name_list = (char **) malloc(sizeof(char *) * 5);

        field_name_list[0] = "id";
        field_name_list[1] = "name";
        field_name_list[2] = "password";
        field_name_list[3] = "grants";
        field_name_list[4] = "time";
    }

    return field_name_list;
}

int *analyst_analysis_sql_create_sys_table_get_field_type_list(char *command, char *table_name) {

    int *field_type_list = (int *) malloc(sizeof(int) * 4);

    if (0 == strcmp("databases_manage", table_name)) {

        field_type_list[0] = FIELD_TYPE_INT;
        field_type_list[1] = FIELD_TYPE_STRING;
        field_type_list[2] = FIELD_TYPE_STRING;
        field_type_list[3] = FIELD_TYPE_STRING;
    } else if (0 == strcmp("tables_manage", table_name)) {

        field_type_list[0] = FIELD_TYPE_INT;
        field_type_list[1] = FIELD_TYPE_STRING;
        field_type_list[2] = FIELD_TYPE_STRING;
        field_type_list[3] = FIELD_TYPE_STRING;
    } else if (0 == strcmp("users", table_name)) {

        free(field_type_list);
        field_type_list = (int *) malloc(sizeof(int) * 5);

        field_type_list[0] = FIELD_TYPE_INT;
        field_type_list[1] = FIELD_TYPE_STRING;
        field_type_list[2] = FIELD_TYPE_STRING;
        field_type_list[3] = FIELD_TYPE_STRING;
        field_type_list[4] = FIELD_TYPE_STRING;
    }

    return field_type_list;
}