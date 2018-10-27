#include <stdlib.h>
#include <string.h>
#include "../ui/ui.h"
#include "../certificate/certificate.h"


// 命令行模块

// 判断是否登录成功
int command_login_success(int argc, char **argv){

    // 是登录命令
    if( argc>1 && strcmp(strlwr(argv[0]),"sherk")==0 && strcmp(strlwr(argv[1]),"login") == 0 ){

        // 凭证正确
        if(certificate_login(ui_print_login_dialog())){

            system("cls");

            // UI打印出Logo和欢迎语
            ui_print_logo();
            ui_print_welcome();

            return 1;
        }

        // 凭证非法
        return 0;
    }

    // 不是登录命令
    ui_print_illegal_input();

    return 0;
}

// 判断是否退出成功
int command_logout_success(){

    command_sql_interactive_env_loop();

    return 1;
}


// 循环sql输入环境
void command_sql_interactive_env_loop(){

    while(1){

        // UI打印出等待输出的状态
        char *sql = ui_print_wait_for_input();

        // 输入的sql为退出语句
        if(strcmp(sql,"sherk exit")==0||strcmp(sql,"sherk logout")==0){

            free(sql);
            break;
        }
    }


    // 退出sql环境

}