#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <include/helper/color.h>
#include <unistd.h>
#include <module/administrator/administrator.h>

// 输出文字信息
void grocery_console_print(char *s) {

}

// 输出红色字体的文字信息
void grocery_console_print_with_red_color(char *s) {

    printf(RED "%s", s);
    printf("\n");
    printf(NONE);
}

void grocery_console_print_with_blue_color(char *s) {

    printf(BLUE "%s", s);
    printf("\n");
    printf(NONE);
}

// 输出带颜色的字体
void grocery_console_print_with_color(char *color, char *s) {

}

/**
 * 程序错误退出
 * @param string msg
 */
void grocery_exit_with_error(char *msg) {

    // 使用红色
    grocery_console_print_with_red_color(msg);
    exit(-1);
}


int grocery_is_file_exists(char *file) {

    if (0 == access(file, 0)) {

        return 0;
    }

    return -1;
}


char *grocery_read_file(char *file) {

    char *password = (char *) malloc(sizeof(char) * 100);
    memset(password, '\0', sizeof(char) * 100);
    FILE *fp = fopen(file, "r");
    fgets(password, 100, fp);

    fclose(fp);// 必须close才能顺利写入文件

    // 这个处理的时候, 会加上换行, 故需要删除掉换行符
    for (int i = 0; '\0' != password[i] ; ++i) {
        if('\n' == password[i]){
            password[i] = '\0';
        }
    }

    return password;
}


char *grocery_get_password_file(char *name) {

    char *password_file = (char *) malloc(sizeof(char) * 100);

    strcat(password_file, administrator_method_read_config_string("app.server.dir.root"));
    strcat(password_file, administrator_method_read_config_string("app.server.dir.database.home"));
    strcat(password_file, administrator_method_read_config_string("app.server.dir.database.information_schema.home"));
    strcat(password_file,
           administrator_method_read_config_string("app.server.dir.database.information_schema.passwords"));
    strcat(password_file, name);
    strcat(password_file, ".password");

    return password_file;
}