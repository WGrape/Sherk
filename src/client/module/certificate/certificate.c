#include <stdio.h>
#include <windows.h>
#include "../network/network.h"
#include "../../include/object/User.h"

// 凭证模块

// 登录
int certificate_login(User user){

    certificate_print_loadding();

    Sleep(2000);

    return 1;
}

// 退出
int certificate_logout(){


}


void certificate_print_loadding(){

    printf("loadding...\n");
}