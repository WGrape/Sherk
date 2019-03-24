#include <stdio.h>
#include<unistd.h>
#include "module/network/network.h"
#include "include/object/User.h"

void certificate_print_loadding();

// 凭证模块

/**
 * 登录
 * @param user
 * @return int
 *
 */
int certificate_login(User user){

    certificate_print_loadding();

    sleep(2);

    // 凭证正确
    return 0;
}



void certificate_print_loadding(){

    printf("loadding...\n");
}