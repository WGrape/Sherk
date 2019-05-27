#include <stdio.h>
#include<unistd.h>
#include <module/administrator/administrator.h>
#include <string.h>
#include <include/define/rescode.h>
#include <module/encrypter/encrypter.h>
#include <module/grocery/grocery.h>
#include <module/test/test.h>
#include "module/network/network.h"
#include "include/object/User.h"
#include <stdlib.h>

// 凭证模块

User certificate_global_variable_user;


void certificate_print_loadding() {

    // printf("loadding...\n");
}

/**
 * 登录
 * @param user
 * @return int
 *
 */
int certificate_login(User user) {

    certificate_print_loadding();

    // 初始化配置
    administrator_method_init_config();

    // 初始化: read_password_from_file , name 和 password 和 salt
    char md5_password[100];
    char sherk_password[100];
    char read_password_from_file[100];

    char name[100]; // 用户名
    strcpy(name, user.name);

    char password[100]; // 密码
    strcpy(password, user.password);

    char salt[100] = {'\0'}; // salt
    strcpy(salt, administrator_method_read_config_string("app.server.certificate.salt"));


    // 密码文件
    char *password_file = grocery_get_password_file(name);

    // 拼接密码 md5(name + md5(password) + salt) 到 name 中
    strcpy(md5_password, MDString(password));

    strcpy(sherk_password, name);
    strcat(sherk_password, md5_password);
    strcat(sherk_password, salt);
    strcpy(sherk_password, MDString(sherk_password));

    // 如果密码文件不存在, 则说明账号不存在
    if (RES_OK != grocery_is_file_exists(password_file)) {

        test_generate_sherk_password(NULL, name, password, salt);
        return -1;
    }

    // 无论是否有密码文件, 都先生成密码, 防止密码文件被删除后, 无法自己创建加密信息
    test_generate_sherk_password(password_file, name, password, salt);

    // 读取文件中存储的密码
    strcpy(read_password_from_file, grocery_read_file(password_file));

    if (0 != strcmp(sherk_password, read_password_from_file)) {

        return -2;
    }

    // 赋给全局变量
    // certificate_global_variable_user.name = user.name; 这样错是因为user是局部变量会被销毁, 所以导致全局变量的内容仍旧为空
    // certificate_global_variable_user.password = user.password;
    certificate_global_variable_user.name = (char *) malloc(sizeof(char) * 100);
    certificate_global_variable_user.password = (char *) malloc(sizeof(char) * 100);
    strcpy(certificate_global_variable_user.name, name);
    strcpy(certificate_global_variable_user.password, md5_password);

    // sleep(2);

    // 凭证正确
    return 0;
}
