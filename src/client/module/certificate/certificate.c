#include <stdio.h>
#include <windows.h>
#include "module/network/network.h"
#include "include/object/User.h"

// 凭证模块

/**
 * 登录
 * @param user
 * @return int
 *
 */
int certificate_login(User user){

    certificate_print_loadding();

    Sleep(2000);

    // 凭证正确
    return 0;
}



void certificate_print_loadding(){

    printf("loadding...\n");
}