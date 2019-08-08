#include <stdio.h>
#include <SherkSupport/src/include/serialize/tobe_serialized_structs.h>
#include <stdlib.h>
#include <SherkSupport/src/include/static/generator.h>
#include <sys/time.h>
#include <string.h>
#include <memory.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <SherkSupport/src/module/skeleton/skeleton.h>
#include <SherkService/mechanism/module/administrator/administrator.h>
#include <SherkSupport/src/module/maintainer/callback/infoschema_callback/infoschema_callback.h>


/**
 * Disk操作: Show databases
 */
FILE *database_in_disk_maintainer_show_databases(int delete) {

    // 用 ls 方法
    char shell[100];
    sprintf(shell, "cd %s && ls > ./temp_show_databases.txt", administrator_method_read_config_string_database());
    // printf("shell:%s---------------\n", shell);
    system(shell);

    char file[100];
    sprintf(file, "%stemp_show_databases.txt", administrator_method_read_config_string_database());
    FILE *fp = fopen(file, "r");
    if (NULL == fp) {
        grocery_exit_with_error("failed to open temp_show_databases.txt");
    }

    if (delete) {

        sprintf(shell, "rm %s", file);
        system(shell);
    }

    return fp;
}

/**
 * Disk操作: 创建数据库
 * @param database_name
 */
void database_in_disk_maintainer_create_database(char *database_name, int infoschema_callback) {

    char *dir = grocery_concat_database_location_string(database_name);
    char shell[100] = "mkdir -p "; // 存在则忽略
    strcat(shell, dir);
    // printf("-------shell = %s ------\n", shell);
    system(shell);

    if (INFOSCHEMA_CALLBACK_ABLE == infoschema_callback) {

        // 开启系统表回调
        infoschema_callback_active(0, database_name, "databases_manage", NULL, NULL, grocery_get_random_md5_string_6(),
                                   grocery_time_get_now());
    }

}

/**
 * Disk操作: 删除数据库
 * @param database_name
 * @param infoschema_callback
 */
void database_in_disk_maintainer_drop_database(char *database_name, int infoschema_callback) {

    char *dir = grocery_concat_database_location_string(database_name);
    char shell[100] = "rm -r "; // 存在则忽略, -f 可以在文件不存在时直接忽略错误, 但是太危险了, 最好还是别 -f
    strcat(shell, dir);
    // printf("-------shell = %s ------\n", shell);
    system(shell);

    if (INFOSCHEMA_CALLBACK_ABLE == infoschema_callback) {

        // 开启系统表回调
        // infoschema_callback_insert_record();
    }
}
