#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <include/define/const.h>
#include "module/ui/ui.h"
#include "module/certificate/certificate.h"
#include "module/express/express.h"
#include "include/define/rescode.h"
#include "include/define/exitcode.h"
#include "include/helper/string.h"

// 命令行模块

// 判断是否登录成功
int command_login_success(int argc, char **argv) {

    // 是登录命令
    if (argc > 1 && strcmp(strtolower(argv[0]), "sherk") == 0 && strcmp(strtolower(argv[1]), "login") == 0) {

        // 凭证正确
        if (RES_OK == certificate_login(ui_print_login_dialog())) {

            system("cls");

            // UI打印出Logo和欢迎语
            ui_print_logo();
            ui_print_welcome();

            return 0;
        }

        // 凭证错误
        ui_print_account_not_exist();
        return 1;
    }

    // 不是合法的命令
    ui_print_illegal_input();
    return -1;
}

// 判断是否退出成功
int command_logout_success(int exitCode) {

    if (EXIT_NATURAL == exitCode) {

        // 如果是正常退出, 则做清理回收操作

    }

    ui_print_bye();

    return 0;
}


// 进入sql交互环境
void command_enter_sql_interactive_env() {

    char sql[CONST_SQL_SIZE], buffer[CONST_BUFFER_SIZE];

    while (1) {

        memset(sql, '\0', sizeof(char) * CONST_SQL_SIZE);
        memset(buffer, '\0', sizeof(char) * CONST_BUFFER_SIZE);

        // UI打印出等待输出的状态, sql最短为2个字符
        ui_print_wait_for_input(sql);

        // 输入的sql为退出语句
        if (strcmp(sql, "sherk exit") == 0 || strcmp(sql, "sherk logout") == 0) {

            break;
        } else {

            // UI打印出 sql 查询的结构( 快递模块接收 sql 语句 )
            express_transport_sql(sql, buffer);
            ui_print_sql_response_data(buffer);
        }
    }

}
