#ifndef CLIENT_INCLUDE_HELPER_EXIT_H
#define CLIENT_INCLUDE_HELPER_EXIT_H

#include <stdlib.h>
#include <stdio.h>
#include "console.h"

/**
 * 程序错误退出
 * @param string msg
 */
void exit_with_error(char *msg){

    // 使用红色
    console_print_with_red_color(msg);
    exit(0);
}


#endif
