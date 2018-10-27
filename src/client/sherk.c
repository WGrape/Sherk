
#include "module/command/command.h"

int main(int argc, char argv[]) {

    // 登录
    command_login_success(argc, argv);

    // 退出
    command_logout_success();

    return 0;
}
