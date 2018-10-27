#include <stdio.h>
#include "../ui/ui.h"
#include "../login/login.h"

// 命令行模块

// 判断是否是登录命令
int command_login_success(int argc, char argv[]){

    // 是登录命令
    if( argc>1 && argv[0] == "sherk" && argv[1] == "login" ){

        ui_print_login_dialog();
        return 1;
    }

    // 不是登录命令
    ui_print_illegal_input();

    return 0;
}

// 命令是退出
int command_is_logout(int argc, char argv[]){

    if( argv[1] == 'logout' ){

        return 1;
    }

    return 1;
}

int command_handle_login(){


}
