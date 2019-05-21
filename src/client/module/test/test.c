#include <stdio.h>
#include <module/administrator/administrator.h>
#include <module/encrypter/encrypter.h>
#include <string.h>
#include <include/define/rescode.h>
#include <module/grocery/grocery.h>


// md5( lvsi + md5(123456) + 08f2a4c2f6983f2880d32 )
// md5(123456) = e10adc3949ba59abbe56e057f20f883e
// lvsie10adc3949ba59abbe56e057f20f883e08f2a4c2f6983f2880d32
// md5(lvsie10adc3949ba59abbe56e057f20f883e08f2a4c2f6983f2880d32) = 1a608fd277cbd9485297c1716cb81ac4
char *test_generate_sherk_password(char *password_file, char *name, char *password, char *salt) {

    // sherk_password
    char sherk_password[200]; // 开100还不够

    // 初始化配置
    administrator_method_init_config();

    // md5 password
    char md5_password[100];
    strcpy(md5_password, MDString(password));

    // 拼接生成 sherk_password
    strcpy(sherk_password, name);
    strcat(sherk_password, md5_password);
    strcat(sherk_password, salt);
    strcpy(sherk_password, MDString(sherk_password));

    // 读取文件中存储的密码
    char read_password_from_file[100] = {'\0'};
    strcpy(read_password_from_file, grocery_read_file(password_file));

    printf("\n\n");
    printf("------------------------------------------------------------------------------------------\n");
    printf("| The following is the generated security credential \n");
    printf("------------------------------------------------------------------------------------------\n");
    printf("| name                    | %s \n", name);
    printf("| password                | %s \n", password);
    printf("| like-md5 password       | %s \n", md5_password);
    printf("| salt                    | %s \n", salt);
    printf("| sherk_password          | %s \n", sherk_password);
    printf("| read_password_from_file | %s \n", read_password_from_file);
    printf("| password_file           | %s \n", password_file);
    printf("----------------------------------------------------------------------------------------\n\n");

}

