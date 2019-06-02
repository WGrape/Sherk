#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SherkSQL/src/module/parser/parser.h>
#include <SherkService/mechanism/module/variable_master/variable_master.h>
#include <SherkService/mechanism/module/administrator/administrator.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <SherkStorage/src/vendor/storage_serialization/module/bookworm/bookworm.h>

extern Variable_Master_Session_Variables variable_master_session_variables;

void test_log_print_level_is_access(){

}

void test_log_print_level_is_debug(){

}

void test_log_print_level_is_error(){

}

void test_log_print_sql_bin(){

}

void test_log_print_sql_query(){

}

void test_log_print_sql_slow(){

}

// 打印所有的日志, 每个类型的日志都只打印前100条
void test_log_print_log() {

    int i;

    // 只有在调试模式下打印
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("| Users \n");
    printf("--------------------------------------------------\n");
    printf("| id | name | password | \n");

    // 依次打印每个用户
    // 用 ls 方法
    char shell[100];
    sprintf(shell, "cd %s && ls > ./temp_show_users.txt",
            "/Users/yimutian/sherk/database/information_schema/user.password");
    // printf("shell:%s---------------\n", shell);
    system(shell);

    char *file = "/Users/yimutian/sherk/database/information_schema/user.password/temp_show_users.txt";
    char *certificate;
    int end;
    for (i = 1;; ++i) {

        certificate = bookworm_read_x_line(file, i);
        if (NULL == certificate) {
            break;
        }

        if('\n' == certificate[ strlen(certificate)-1 ]){

            certificate[ strlen(certificate)-1 ]= '\0';
        }

        if (0 == strcmp("temp_show_users.txt", certificate)) {

            continue;
        }

        end = grocery_string_get_str_first_char_index(certificate, ".password", 0);

        printf("| %d  | %s | ******** \n", i, grocery_string_cutwords(certificate, 0, end - 1));
    }

    system("rm /Users/yimutian/sherk/database/information_schema/user.password/temp_show_users.txt");

    printf("--------------------------------------------------\n");

}

