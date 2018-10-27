#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "../../include/define/const.h"
#include "../../include/object/User.h"

// 打印出登录对话框
User ui_print_login_dialog() {

    char name[30];
    char password[30];

    while (1) {

        // 输入用户名
        printf("Please input your name : ");
        scanf("%s", name);

        // 吃掉回车
        getchar();

        // 安全显示输入的密码
        printf("Please input your password : ");
        ui_password_input_safely(password);

        // 判断用户名和密码是否合法
        int len1 = strlen(name), len2 = strlen(password);
        if (len1 < 5 || len1 > 20 || len2 < 5 || len2 > 20) {

            printf("Your name or password is not valid\n");
        } else {

            break;
        }
    }

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
char *ui_print_wait_for_input() {

    char *sql = (char *) (malloc(sizeof(char) * 100000)); // 暂定10万个字符
    printf("sherk > ");
    scanf("%s", sql);
    return sql;
}

// 安全的输入密码
void ui_password_input_safely(char *password) {

    char c;
    for (int i = 0;;) {

        c = getch();

        // 如果是删除键
        if ((int) (c) == 8) {

            if (i > 0) {

                i = i - 1;
                printf("\b \b");
            }
        }
            // 如果是回车键
        else if (c == '\n' || c == '\r') {

            password[i] = '\0';
            putchar('\n');
            break;
        }
            // 不是删除键也不是回车键，则输出星号
        else {

            password[i] = c;
            putch('*');
            ++i;
        }
    }
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
