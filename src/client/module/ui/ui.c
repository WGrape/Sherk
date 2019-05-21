#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "include/define/const.h"
#include "include/object/User.h"
#include <termios.h>
#include<unistd.h>

#ifndef CLIENT_INCLUDE_HELPER_CONSOLE_H

#include <module/grocery/grocery.h>

#endif

void ui_handle_enter_key(char *sql);


// 登录成功时，打印欢迎语
void ui_print_welcome() {

    printf("Welcome ! The sherk client star-up successfully !\n\n");
}

// 打印出非法输入
void ui_print_illegal_input() {

    printf("illegal input!\n");
}

// 打印出等待输入
void ui_print_wait_for_input(char *sql) {

    printf("sherk > ");

    char segment[100];
    segment[0] = ' ';

    int empty_buffer = 1;

    // 处理回车键问题(不断敲回车时，就不断的换行)
    ui_handle_enter_key(sql);

    // 解决命令中有空格的问题
    while (empty_buffer || '\n' != getchar()) {

        scanf("%s", &segment[1]);

        if (empty_buffer) {

            strcat(sql, &segment[1]);
        } else {

            strcat(sql, segment);
        }

        memset(segment, '\0', 100);
        segment[0] = ' ';

        empty_buffer = 0;
    }

    // printf("%s\n",sql);
}

// 安全的输入密码
char *ui_password_input_safely(char *password) {

    struct termios old, new;//old保存当前的终端参数，new用来保存修改后的终端参数
    tcgetattr(0, &old);//将tcgetattr()获取到的stdin（标准输入流）的参数存到old中
    new = old;//将该参数复制一份到new中
    new.c_lflag &= ~(ECHO | ICANON);//修改new中的ECHO和ICANON参数，使得new为不回显输入内容
    tcsetattr(0, TCSANOW, &new);//将修改后的new设置为stdin的新的参数，并立即生效

    memset(password, 0, 20);//每次重新输入以前都要清空一次buf
    fgets(password, 20, stdin);

    tcsetattr(0, TCSANOW, &old);//登陆成功后恢复原有终端参数，正常回显

    // 这个处理的时候, 会加上换行, 故需要删除掉换行符
    for (int i = 0; '\0' != password[i] ; ++i) {
        if('\n' == password[i]){
            password[i] = '\0';
        }
    }

    return password;
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

// 退出成功时，打印再见语
void ui_print_bye() {

    printf("Thanks for using sherk!\n");
}

// 打印出账号不存在
void ui_print_account_not_exist() {

    grocery_console_print_with_red_color("Account not esist or wrong !\n");
}

// 打印出sql响应的数据
void ui_print_sql_response_data(char *buffer) {

    // printf("ui_print_sql_response_data: %s\n", buffer);

    grocery_console_print_with_blue_color(buffer);

}

// 打印出登录对话框
User ui_print_login_dialog() {

    char name[30];
    char password[30];
    memset(password, '\0', sizeof(password));

    int times = 1;
    while (1) {

        // 输入用户名
        printf("Please enter your name : ");
        scanf("%s", name);
        getchar();

        // 安全显示输入的密码
        printf("Please enter your password : ");
        ui_password_input_safely(password);

        // 判断用此账户是否存在
        if (1) {

            printf("\n");
            break;
        }

        if (times >= 3) {

            ui_print_account_not_exist();
            exit(0);
        }

        ++times;
    }

    User user = {name, password};

    // printf( "此用户的信息是, 用户名: %s , 密码: %s", user.name, user.password );

    return user;
}


// 处理回车问题
void ui_handle_enter_key(char *sql) {

    while (1) {

        char ch = (char) getchar();

        if ('\n' == ch) {

            printf("sherk > ");
        } else {

            memset(sql, '\0', sizeof(*sql));
            sql[0] = ch;
            break;
        }
    }
}