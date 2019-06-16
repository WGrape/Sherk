#include "module/command/command.h"
#include "include/define/rescode.h"

int main(int argc, char **argv) {

    // 退出信号
    int exit_signal;

    // 登录系统
    exit_signal = command_login_success(argc, argv);

    // 凭证正确
    if(RES_OK == exit_signal){

        exit_signal = command_enter_sql_interactive_env();
    }

    // 退出系统
    exit_signal = command_logout_success(exit_signal);

    return exit_signal;
}
