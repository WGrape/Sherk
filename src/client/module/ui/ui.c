#include <stdio.h>
#include "../../include/define/const.h"
#include "../../include/object/User.h"

// 打印出登录对话框
User ui_print_login_dialog(){

    User user;
    char name[30];
    char password[30];
    printf("输入用户名和密码 ：");
    scanf("%s %s",&name,&password);

    return user = {

            name:name,
            password:password
    };
}

// 登录成功时，打印此对话框
void ui_print_welcome(){

    ui_print_logo();
    ui_print_wait_for_input();
}

// 打印出非法输入
void ui_print_illegal_input(){

    printf("illegal input!\n");
}



// 打印出 logo
void ui_print_logo(){

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
}

// 打印出等待输入
void ui_print_wait_for_input(){

    printf("sherk > ");
}
