#include <stdio.h>
#include <stdlib.h>
#include "../../include/define/const.h"
#include "../../include/object/User.h"

// 打印出登录对话框
User ui_print_login_dialog() {

    char name[30];
    char password[30];
    printf("Please input your name and your password : ");
    scanf("%s %s", &name, &password);

    User user = {name, password};

    return user;
}

// 登录成功时，打印此对话框
void ui_print_welcome() {

    printf("Welcome ! The sherk client star-up successfully !\n");
}

// 打印出非法输入
void ui_print_illegal_input() {

    printf("illegal input!\n");
}

// 打印出等待输入
char* ui_print_wait_for_input() {

    char *sql = (char*)(malloc(sizeof(char)*100000)); // 暂定10万个字符
    printf("sherk > ");
    scanf("%s",sql);
    return sql;
}


// 打印出 logo
void ui_print_logo() {

    printf("                                                     \n"
           "                                                     \n"
           "  .--.--.     ,---,                             ,-.  \n"
           " /  /    '. ,--.' |                         ,--/ /|  \n"
           "|  :  /`. / |  |  :                __  ,-.,--. :/ |  \n"
           ";  |  |--`  :  :  :              ,' ,'/ /|:  : ' /   \n"
           "|  :  ;_    :  |  |,--.   ,---.  '  | |' ||  '  /    \n"
           " \\  \\    `. |  :  '   |  /     \\ |  |   ,''  |  :    \n"
           "  `----.   \\|  |   /' : /    /  |'  :  /  |  |   \\   \n"
           "  __ \\  \\  |'  :  | | |.    ' / ||  | '   '  : |. \\  \n"
           " /  /`--'  /|  |  ' | :'   ;   /|;  : |   |  | ' \\ \\ \n"
           "'--'.     / |  :  :_:,''   |  / ||  , ;   '  : |--'  \n"
           "  `--'---'  |  | ,'    |   :    | ---'    ;  |,'     \n"
           "            `--''       \\   \\  /          '--'       \n"
           "                         `----'                      \n"
           "                                                     ");
    printf("\n");
}
