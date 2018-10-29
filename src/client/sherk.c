
#include "module/command/command.h"
#include "include/define/rescode.h"

int main(int argc, char argv[]) {

    // 登录
    if(RES_OK != command_login_success(argc, argv)){

        // 客户端结束 - 登录失败
        return 1;
    }

    // 进入sql交互环境中
    command_enter_sql_interactive_env();

    // 退出
    if(RES_OK != command_logout_success()){

        // 客户端结束 - 退出失败
        return 1;
    }

    // 客户端正常结束
    return 0;
}
