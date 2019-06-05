#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SherkSQL/src/module/parser/parser.h>
#include <SherkService/mechanism/module/variable_master/variable_master.h>
#include <SherkService/mechanism/module/administrator/administrator.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <SherkStorage/src/vendor/storage_serialization/module/bookworm/bookworm.h>

extern Variable_Master_Session_Variables variable_master_session_variables;

void test_privileges_print_privileges() {

    printf("\n");
    printf("--------------------------------------------------------------------\n");
    printf("| Privileges \n");
    printf("--------------------------------------------------------------------\n");
    printf("| id | Privileges | Context          | Comment                     |\n");
    printf("| 0  | Show       | Server Admin     | Show server information     |\n");
    printf("| 1  | Create     | Databases,Tables | Create database or table    |\n");
    printf("| 2  | Drop       | Databases,Tables | Drop database or table      |\n");
    printf("| 3  | Insert     | Tables           | To insert data into tables  |\n");
    printf("| 4  | Delete     | Tables           | To delete exiting rows      |\n");
    printf("| 5  | Update     | Tables           | To update exiting rows      |\n");
    printf("| 6  | Select     | Tables           | To retrieve rows from table |\n");
    printf("--------------------------------------------------------------------\n");
}

// 打印当前用户的权限
void test_privileges_print_grants(){

    // 从全局变量 variable_master_session_variables 中获取当前用户名, 并从user表中读取用户的权限信息

}

