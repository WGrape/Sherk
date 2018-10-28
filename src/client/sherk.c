
#include "module/command/command.h"

int main(int argc, char argv[]) {

    // 登录
    if(!command_login_success(argc, argv)){

        // 登录失败
        return 0;
    }

    // 进入sql交互环境中
    command_enter_sql_interactive_env();

    // 退出
    if(!command_logout_success()){

        // 退出失败
    }

    return 0;
}
