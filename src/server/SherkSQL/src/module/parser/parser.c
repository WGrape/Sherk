#include <stdio.h>
#include <regex.h>
#include <memory.h>
#include <SherkSQL/src/module/interviewer/interviewer.h>
#include <SherkSQL/src/module/analyst/analyst.h>
#include <stdlib.h>
#include <SherkEngine/src/module/executor/executor.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <SherkService/test/module/test_variable/test_variable.h>
#include <SherkService/mechanism/include/define/const.h>
#include <SherkService/mechanism/include/define/rescode.h>
#include <SherkService/test/module/test_network/test_network.h>
#include <SherkService/test/module/automated_test/automated_test.h>
#include <SherkService/test/module/test_users/test_users.h>
#include <SherkSQL/src/module/extractor/extractor.h>
#include <SherkSQL/src/module/builder/builder.h>
#include <SherkService/test/module/test_log/test_log.h>
#include <SherkService/test/module/test_privileges/test_privileges.h>

// 解析原理 : 正则 + 解析树

const int SQL_MAX_PATTRENS = 100;

const int SQL_CATEGORY_IS_SHERK_COMMAND = 1;
const int SQL_CATEGORY_IS_SQL = 2;
const int SQL_CATEGORY_IS_SHERK_COMMAND_IN_SQL = 3;

const int SQL_TYPE_IS_CREATE_DATABASE = 3;
const int SQL_TYPE_IS_CREATE_TABLE = 4;

const int SQL_TYPE_IS_DROP_DATABASE = 5;


/**
 * 匹配正则
 * @param pattern
 * @param sql
 * @return
 */
int parser_match_regex(const char *pattern, const char *sql) {
    int result = 0;

    regex_t regex;
    int regexInit = regcomp(&regex, pattern, REG_EXTENDED);
    if (!regexInit) {

        int reti = regexec(&regex, sql, 0, NULL, 0);

        if (REG_NOMATCH != reti) {

            result = 1; // 匹配到
        }
    }
    // printf("匹配, patter:%s, sql:%s, result:%d\n", pattern, sql, result);
    regfree(&regex);
    return result;
}

int parser_match_sql_execute_system(char *sql, char *res) {

    // char *show_tables_pattern = "^\\s*show tables.*$";

    char *flush_privileges_pattern = "^\\s*flush privileges.*$";

    char *flush_tables_pattern = "^\\s*flush tables.*$";


}

/**
 * 解析匹配与查看系统相关的SQL
 * @param sql
 * @return
 */
int parser_match_sql_show_system(char *sql, char *res) {

    // show tables
    char *show_tables_pattern = "^\\s*show tables.*$";

    // show variables;
    char *show_variables_pattern = "^\\s*show variables.*$";

    // show network;
    char *show_network_pattern = "^\\s*show network.*$";

    // show users;
    char *show_users_pattern = "^\\s*show users.*$";

    // show logs; 支持 show log 和 show logs 2种
    char *show_logs_pattern = "^\\s*show logs.*$";

    // show privileges, 展示系统支持的全部权限
    char *show_privileges_pattern = "^\\s*show privileges.*$";

    // show grants , 展示此用户当前的权限
    char *show_grants_pattern = "^\\s*show grants.*$";

    // Todo: show usage 查看系统使用情况

    // 匹配 SQL: show variables
    if (parser_match_regex(show_variables_pattern, sql)) {

        test_variable_print_variable();
        sprintf(res, "Show Variables Success.\n");

        return 1;
    }
        // 匹配 SQL: show network
    else if (parser_match_regex(show_network_pattern, sql)) {

        test_network_print_network_directly();
        sprintf(res, "Show Network Success.\n");

        return 1;
    }

        // 匹配 SQL: show users
    else if (parser_match_regex(show_users_pattern, sql)) {

        test_users_print_users();
        sprintf(res, "Show Users Success.\n");

        return 1;
    }

        // 匹配 SQL: show privileges
    else if (parser_match_regex(show_privileges_pattern, sql)) {

        test_privileges_print_privileges();
        sprintf(res, "Show Privileges Success.\n");

        return 1;
    }

        // 匹配 SQL: show grants
    else if (parser_match_regex(show_grants_pattern, sql)) {

        test_privileges_print_privileges();
        sprintf(res, "Show Grants Success.\n");

        return 1;
    }

        // 匹配 SQL: show logs
    else if (parser_match_regex(show_logs_pattern, sql)) {

        if (-1 < grocery_string_get_str_first_char_index(show_logs_pattern, "access", 0)) {

            test_log_print_level_is_access();
        } else if (-1 < grocery_string_get_str_first_char_index(show_logs_pattern, "debug", 0)) {

            test_log_print_level_is_debug();
        } else if (-1 < grocery_string_get_str_first_char_index(show_logs_pattern, "error", 0)) {

            test_log_print_level_is_error();
        } else if (-1 < grocery_string_get_str_first_char_index(show_logs_pattern, "bin", 0)) {

            test_log_print_sql_bin();
        } else if (-1 < grocery_string_get_str_first_char_index(show_logs_pattern, "query", 0)) {

            test_log_print_sql_query();
        } else if (-1 < grocery_string_get_str_first_char_index(show_logs_pattern, "slow", 0)) {

            test_log_print_sql_slow();
        } else {

            test_log_print_log();
        }

        sprintf(res, "Show Logs Success.\n");
        return 1;
    }

    return 0;
}

/**
 * 解析匹配与表相关的SQL
 * @param sql
 * @return
 */
int parser_match_sql_table(char *sql, char *res) {

    // show tables
    char *show_tables_pattern = "^\\s*show tables.*$";

    // show columns : 如 SHOW COLUMNS FROM testalter_tbl
    char *show_columns_pattern = "";

    // create table 数据表名(
    //
    //     id   INT,
    //     name INT,
    //     age  INT
    // );
    // ^create\s+table\s+.+\s*\((\s+.+\s+(int|float|char|string)\s+,)+\)$
    char *create_table_pattern = "^\\s*create table .*$";

    // desc table 数据表名
    char *desc_table_pattern = "^\\s*desc table .*$";

    // desc table field 数据表名
    char *desc_table_field_pattern = "^\\s*desc table field .*$";

    // drop table 数据表名
    char *drop_table_pattern = "^\\s*drop table .*$";

    // select * from 表名
    char *select_table_pattern = "^\\s*select \\* from .*$";

    // select table 数据表名
    char *select_table_part_pattern = "^\\s*select table .*$";

    // insert 数据表名
    char *insert_table_pattern = "^\\s*insert into .*$";

    // update 数据表名
    char *update_table_pattern = "^\\s*update .*$";

    // delete from 记录 - DELETE FROM table_name WHERE some_column=some_value;
    char *delete_from_table_pattern = "^\\s*delete from .*$";

    // Alter Table xx Drop column : 删除列
    char *alter_table_drop_column_pattern = "^\\s*delete from .*$";

    // Alter Table xx ADD column column_type : 增加列
    char *alter_table_add_column_pattern = "^\\s*delete from .*$";


    // 匹配 SQL: show tables
    if (parser_match_regex(show_tables_pattern, sql)) {

        if (RES_OK != executor_handle_sql_show_tables()) {

            sprintf(res, "Please Use Database Firstly.\n");
        } else {
            sprintf(res, "Show Tables Success.\n");
        };

        return 1;
    }
        // 匹配 SQL: create table
    else if (parser_match_regex(create_table_pattern, sql)) {

        char *table_name = analyst_analysis_sql_create_table_get_table_name(sql);
        char **field_name_list = (char **) malloc(sizeof(char **) * 100);
        int *field_type_list = (int *) malloc(sizeof(int *) * 100);
        int field_count = 0;

        if (analyst_analysis_sql_is_create_sys_table(table_name)) {

            // 创建系统表操作
            field_name_list = analyst_analysis_sql_create_sys_table_get_field_name_list(sql, table_name);
            field_type_list = analyst_analysis_sql_create_sys_table_get_field_type_list(sql, table_name);
            field_count = (0 == strcmp("users", table_name)) ? 5 : 4;
        } else {

            // 创建非系统表操作
            //field_name_list = analyst_analysis_sql_create_table_get_field_name_list(sql);
            //field_type_list = analyst_analysis_sql_create_table_get_field_type_list(sql);
            extractor_extract_create_sql(sql, field_name_list, field_type_list, &field_count);
        }

        // for (int i = 0; i <= 2; ++i) { printf("%s----\n", field_name_list[i]); }
        // printf("-------------------------\n");
        // for (int i = 0; i <= 2; ++i) { printf("%d----\n", field_type_list[i]); }

        int create_table_code = executor_handle_sql_create_table(table_name, field_name_list, field_type_list,
                                                                 field_count);

        if (1 == create_table_code) {

            // 请先选择数据库
            sprintf(res, "Please Use Database Firstly.\n");
        } else if (2 == create_table_code) {

            // 创表语句有错误
            sprintf(res, "Your Create Table SQL With a Error.\n");
        } else if (3 == create_table_code) {

            // 表已存在
            sprintf(res, "The Same Table Already Taken.\n");
        } else {

            sprintf(res, "Create %s Table Success.\n", table_name);
        }

        return 1;
    }
        // 匹配 SQL: drop table
    else if (parser_match_regex(drop_table_pattern, sql)) {

        char *table_name = analyst_analysis_sql_drop_table_get_table_name(sql);
        executor_handle_sql_drop_table(table_name);
        sprintf(res, "Drop %s Table Success.\n", table_name);

        return 1;
    }

        // 匹配 SQL: delete from 表 where
    else if (parser_match_regex(delete_from_table_pattern, sql)) {

        char *table_name = analyst_analysis_sql_delete_from_table_get_table_name(sql);
        executor_handle_sql_delete_table(table_name);
        sprintf(res, "Delete %s Table Success.\n", table_name);

        return 1;
    }

        // 匹配 SQL: desc table field (必须先匹配 desc table field, 后匹配 desc table)
    else if (parser_match_regex(desc_table_field_pattern, sql)) {

        char *table_name = analyst_analysis_sql_desc_table_field_get_table_name(sql);
        int desc_table_code = executor_handle_sql_desc_table_field(table_name);

        if (1 == desc_table_code) {

            sprintf(res, "Please Use Database Firstly.\n");
        } else if (2 == desc_table_code) {

            sprintf(res, "This Table Not Exists.\n");
        } else {
            sprintf(res, "Desc Table Field Success.\n");
        }

        return 1;
    }

        // 匹配 SQL: desc table (必须先匹配 desc table field, 后匹配 desc table)
    else if (parser_match_regex(desc_table_pattern, sql)) {

        char *table_name = analyst_analysis_sql_desc_table_get_table_name(sql);
        int desc_table_code = executor_handle_sql_desc_table(table_name);

        if (1 == desc_table_code) {

            sprintf(res, "Please Use Database Firstly.\n");
        } else if (2 == desc_table_code) {

            sprintf(res, "This Table Not Exists.\n");
        } else {
            sprintf(res, "Desc Table Success.\n");
        }

        return 1;
    }

        // 匹配 SQL: select * from table
    else if (parser_match_regex(select_table_pattern, sql)) {

        char *table_name = analyst_analysis_sql_select_table_get_table_name(sql);
        int select_table_code = executor_handle_sql_select_table(table_name);

        if (1 == select_table_code) {

            sprintf(res, "Please Use Database Firstly.\n");
        } else if (2 == select_table_code) {

            sprintf(res, "This Table Not Exists.\n");
        } else {
            sprintf(res, "Select Table Success.\n");
        }

        return 1;
    }

        // 匹配 SQL: select table 表名
    else if (parser_match_regex(select_table_part_pattern, sql)) {

        char *table_name = analyst_analysis_sql_select_table_part_get_table_name(sql);

        printf("\n实际执行SQL: select * from %s where id = 3", table_name);

        int select_table_part_code = executor_handle_sql_select_table_part(table_name);

        if (1 == select_table_part_code) {

            sprintf(res, "Please Use Database Firstly.\n");
        } else if (2 == select_table_part_code) {

            sprintf(res, "This Table Not Exists.\n");
        } else {
            sprintf(res, "Select Table Success.\n");
        }

        return 1;
    }

        // 匹配 SQL: insert table 表名
    else if (parser_match_regex(insert_table_pattern, sql)) {

        char *table_name = analyst_analysis_sql_insert_table_get_table_name(sql);

        char **field_name_list = (char **) malloc(sizeof(char **) * 100);
        int *field_type_list = (int *) malloc(sizeof(int *) * 100);
        int *field_value_int = (int *) malloc(sizeof(int *) * 100);
        float *field_value_float = (float *) malloc(sizeof(float *) * 100);
        char *field_value_char = (char *) malloc(sizeof(char *) * 100);
        char **field_value_string = (char **) malloc(sizeof(char **) * 100);
        int field_count = 0;

        extractor_extract_insert_sql(sql, &field_count, field_name_list, field_type_list, field_value_int,
                                     field_value_float, field_value_char, field_value_string);

        // char *record = analyst_analysis_sql_insert_table_get_record(sql);
        char *record = builder_generate_record_json(field_count, field_name_list, field_type_list, field_value_int,
                                                    field_value_float, field_value_char, field_value_string);

        int insert_table_code = executor_handle_sql_insert_table(table_name, record);

        if (1 == insert_table_code) {

            sprintf(res, "Please Use Database Firstly.\n");
        } else if (2 == insert_table_code) {

            sprintf(res, "This Table Not Exists.\n");
        } else {
            sprintf(res, "Insert Table Success.\n");
        }

        return 1;
    }

        // 匹配 SQL: update 表名
    else if (parser_match_regex(update_table_pattern, sql)) {

        // 获取数据表名
        char *table_name = analyst_analysis_sql_update_table_get_table_name(sql);

        // 提取 update sql 语句中的参数
        char **field_name_list = (char **) malloc(sizeof(char **) * 100);
        int *field_type_list = (int *) malloc(sizeof(int *) * 100);
        int *field_value_int = (int *) malloc(sizeof(int *) * 100);
        float *field_value_float = (float *) malloc(sizeof(float *) * 100);
        char *field_value_char = (char *) malloc(sizeof(char *) * 100);
        char **field_value_string = (char **) malloc(sizeof(char **) * 100);
        int field_count = 0;

        char **condition_name_list = (char **) malloc(sizeof(char **) * 100);
        char **condition_operator_list = (char **) malloc(sizeof(char **) * 100);
        char **condition_value_list = (char **) malloc(sizeof(char **) * 100);

        extractor_extract_update_sql(sql, &field_count, field_name_list, field_type_list, field_value_int,
                                     field_value_float, field_value_char, field_value_string, condition_name_list,
                                     condition_operator_list, condition_value_list);

        int update_table_code = executor_handle_sql_update_table(table_name, field_count, field_name_list,
                                                                 field_type_list, field_value_int,
                                                                 field_value_float, field_value_char,
                                                                 field_value_string, condition_name_list,
                                                                 condition_operator_list, condition_value_list);

        if (1 == update_table_code) {

            sprintf(res, "Please Use Database Firstly.\n");
        } else if (2 == update_table_code) {

            sprintf(res, "This Table Not Exists.\n");
        } else {
            sprintf(res, "Update Table Success.\n");
        }

        return 1;
    }


    return 0;
}

/**
 * 解析匹配与数据库相关的SQL
 * @param sql
 * @return
 */
int parser_match_sql_database(char *sql, char *res) {

    // show databases
    char *show_databases_pattern = "^\\s*show databases.*$";

    // use 数据库名;
    char *use_database_pattern = "^\\s*use.+$"; // "^\s*use\s+.+$" - 这样写匹配不到,  "^\\s*use.+$" - 这样写可以匹配到

    // create database 数据库名
    char *create_database_pattern = "^\\s*create database .*$";

    // drop database 数据库名
    char *drop_database_pattern = "^\\s*drop database .*$";


    // 匹配 SQL: show databases
    if (parser_match_regex(show_databases_pattern, sql)) {

        executor_handle_sql_show_databases();
        sprintf(res, "Show Databases Success.\n");

        return 1;
    }
        // 匹配 SQL: use database
    else if (parser_match_regex(use_database_pattern, sql)) {

        char *database_name = analyst_analysis_sql_use_database_get_database_name(sql);
        executor_handle_sql_use_database(database_name);
        sprintf(res, "Database Change to %s Success.\n", database_name);

        return 1;
    }
        // 匹配 SQL: create database
    else if (parser_match_regex(create_database_pattern, sql)) {

        char *database_name = analyst_analysis_sql_create_database_get_database_name(sql);
        executor_handle_sql_create_database(database_name);
        sprintf(res, "Create %s Database Success.\n", database_name);

        return 1;
    }
        // 匹配 SQL: drop database
    else if (parser_match_regex(drop_database_pattern, sql)) {

        char *database_name = analyst_analysis_sql_create_database_get_database_name(sql);
        executor_handle_sql_drop_database(database_name);
        sprintf(res, "Drop %s Database Success.\n", database_name);

        return 1;
    }

    return 0;
}

/**
 * 解析匹配SQL
 * @param sql
 * @return
 */
char *parser_match_sql(char *sql) {

    char *res = (char *) malloc(sizeof(char) * CONST_RESPONSE_SIZE);
    memset(res, '\0', sizeof(char) * CONST_RESPONSE_SIZE);

    // 登录判断

    // 匹配与数据表相关的SQL
    if (parser_match_sql_table(sql, res)) {

        return res;
    }
        // 匹配与数据库相关的SQL
    else if (parser_match_sql_database(sql, res)) {

        return res;
    }
        // 匹配与查看系统相关的SQL
    else if (parser_match_sql_show_system(sql, res)) {

        return res;
    }
        // 匹配与执行系统相关的SQL
    else if (parser_match_sql_execute_system(sql, res)) {

        return res;
    } else {

        return "Illegal SQL, Parse Error !\n";
    }
}

/**
 * 解析匹配Sherk命令
 * @param command
 * @return
 */
char *parser_match_command(char *command) {

    // 解析 sherk login 命令
    char *s = grocery_string_cutwords(command, 0, 4);
    if (0 == strcmp("login", s)) {

        char *name = analyst_analysis_command_login_get_name(command);
        char *password = analyst_analysis_command_login_get_password(command);
        executor_handle_command_login(name, password);
        return "Login Success !"; // 必须有响应, 否则network不会send, 程序就会死循环
    }

    // 解析 sherk test clear 命令
    s = grocery_string_cutwords(command, 0, 9);
    if (0 == strcmp("test clear", s)) {

        automated_test_main(1);
        return "All test data have been cleared !";
    }

    // 解析 sherk test reload system 命令
    s = grocery_string_cutwords(command, 0, 17);
    if (0 == strcmp("test reload system", s)) {

        automated_test_main(2);
        return "System Has been Reload !";
    }

    // 解析 sherk test 命令
    s = grocery_string_cutwords(command, 0, 3);
    if (0 == strcmp("test", s) && 0 == strcmp("test", &command[0])) {

        automated_test_main(1);
        automated_test_main(2);
        automated_test_main(0);
        return "Please check the results on the left side carefully !";
    }

    return "Illegal SQL, Parse Error !\n";
}

/**
 * 执行解析
 * @param sql
 * @return
 */
char *parser_exec(char *sql) {

    grocery_string_tolower(sql);

    // 分析SQL的类型
    int sql_category = analyst_analysis_sql_category(sql);

    // 让 variable_master 去记忆SQL
    interviewer_call_variable_master_memory_sql(sql, sql_category);

    // 分类不同的SQL
    if (SQL_CATEGORY_IS_SHERK_COMMAND_IN_SQL == sql_category) {

        // SQL 是 Sherk Command In SQL: sql=sherk test
        // 意思也就是在SQL交互环境中输入系统命令
        // 即转交给 parser_match_command 的时候, 它只接受 sherk (包括空格)后的命令, 如 test
        return parser_match_command(&sql[10]);
    } else if (SQL_CATEGORY_IS_SHERK_COMMAND == sql_category) {

        // SQL 是 Sherk Command: command=
        return parser_match_command(&sql[8]);
    } else if (SQL_CATEGORY_IS_SQL == sql_category) {

        // SQL 是 SQL 命令: sql=
        return parser_match_sql(&sql[4]);
    } else {

        return "Illegal SQL, Parse Error !\n";
    }
}

/**
 * 生成执行计划
 */
void parser_make_execution_plan() {}
