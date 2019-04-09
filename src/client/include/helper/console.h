#ifndef CLIENT_INCLUDE_HELPER_CONSOLE_H
#define CLIENT_INCLUDE_HELPER_CONSOLE_H

#include <stdio.h>
#include "color.h"

// 输出文字信息
void console_print(char *s){

}

// 输出红色字体的文字信息
void console_print_with_red_color(char *s){

    printf( RED "%s", s);
    printf("\n");
}

// 输出带颜色的字体
void console_print_with_color(){

}


#endif
