#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SherkSQL/src/module/parser/parser.h>
#include <SherkService/mechanism/module/variable_master/variable_master.h>
#include <SherkService/mechanism/module/administrator/administrator.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <SherkStorage/src/vendor/storage_serialization/module/bookworm/bookworm.h>
#include <SherkService/mechanism/include/struct/res_array.h>

extern Variable_Master_Session_Variables variable_master_session_variables;

// 获取全部用户的用户名
RES_ARRAY **test_users_get_users_username() {

    char **users_username = (char **) malloc(sizeof(char **) * 10);

    // 依次打印每个用户
    // 用 ls 方法
    char shell[100];
    sprintf(shell, "cd %s && ls > ./temp_show_users.txt",
            "/Users/yimutian/sherk/database/information_schema/user.password");
    // printf("shell:%s---------------\n", shell);
    system(shell);

    char *file = "/Users/yimutian/sherk/database/information_schema/user.password/temp_show_users.txt";
    char *certificate;
    int i, end;
    for (i = 1;; ++i) {

        certificate = bookworm_read_x_line(file, i);
        if (NULL == certificate) {
            break;
        }

        if ('\n' == certificate[strlen(certificate) - 1]) {

            certificate[strlen(certificate) - 1] = '\0';
        }

        if (0 == strcmp("temp_show_users.txt", certificate)) {

            continue;
        }

        end = grocery_string_get_str_first_char_index(certificate, ".password", 0);

        users_username[i - 1] = grocery_string_cutwords(certificate, 0, end - 1);
    }

    system("rm /Users/yimutian/sherk/database/information_schema/user.password/temp_show_users.txt");

    return users_username;
}

// 获取全部用户的密码
char **test_users_get_users_password() {


}

void test_users_print_users() {

    int i;

    // 只有在调试模式下打印
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("| Users \n");
    printf("--------------------------------------------------\n");
    printf("| id | name | password | \n");

    // 依次打印每个用户
    char **users = test_users_get_users_username();
    for(  )
    printf("| %d  | %s | ******** \n", i, grocery_string_cutwords(certificate, 0, end - 1));

    printf("--------------------------------------------------\n");

}
