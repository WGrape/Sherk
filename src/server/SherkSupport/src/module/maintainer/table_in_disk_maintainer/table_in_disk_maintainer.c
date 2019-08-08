#include <stdio.h>
#include <SherkSupport/src/include/serialize/tobe_serialized_structs.h>
#include <stdlib.h>
#include <SherkSupport/src/include/static/generator.h>
#include <sys/time.h>
#include <string.h>
#include <memory.h>
#include <SherkService/mechanism/module/administrator/administrator.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <SherkSupport/src/module/skeleton/skeleton.h>
#include <SherkService/mechanism/include/define/rescode.h>
#include <SherkStorage/src/module/connector/connector.h>
#include <SherkService/test/module/test_table/test_table.h>
#include <SherkStorage/src/vendor/storage_serialization/module/bookworm/bookworm.h>

void table_in_disk_maintainer_desc_table(char *table_frm_file) {

    Struct_Table *struct_table_pointer = connector_read_frm(table_frm_file);
    test_table_print_table_struct_info(struct_table_pointer);
}

void table_in_disk_maintainer_desc_table_field(char *table_field_file) {

    Struct_Table *struct_table_pointer = connector_read_field(table_field_file);
    test_table_print_table_head_info(struct_table_pointer);
}

int table_in_disk_maintainer_table_is_exist(char *database_name, char *table_name) {

    char *path = grocery_concat_table_location_string(database_name, table_name);
    return grocery_is_file_exists(path);
}

void table_in_disk_maintainer_select_table_where_by_id(Struct_Table *struct_table_pointer, int operator, int id) {

    if (OPERATOR_LESS == operator) {

        test_table_print_table_part_info(struct_table_pointer, 1, id - 1);
    } else if (OPERATOR_EQ == operator) {

        test_table_print_table_part_info(struct_table_pointer, id, id);
    } else if (OPERATOR_MORE == operator) {

        test_table_print_table_part_info(struct_table_pointer, id + 1, struct_table_pointer->record_counts);
    } else if (OPERATOR_LESS_EQ == operator) {

        test_table_print_table_part_info(struct_table_pointer, 1, id);

    } else if (OPERATOR_MORE_EQ == operator) {

        test_table_print_table_part_info(struct_table_pointer, id, struct_table_pointer->record_counts);
    } else {

        grocery_exit_with_error("错误的操作符\n");
    }
}

Struct_Table *table_in_disk_maintainer_select_table(char *database_name, char *table_name) {

    char *frm_file = grocery_concat_table_frm_location_string(database_name, table_name);
    char *table_file = grocery_concat_table_location_string(database_name, table_name);
    char *field_file = grocery_concat_table_field_location_string(database_name, table_name);

    // 把 .frm 文件逆序列化到内存中
    Struct_Table *struct_table_pointer = connector_read_frm(frm_file);

    // 把 .field 文件逆序列化到内存中
    Struct_Table *struct_table_pointer_temp = connector_read_field(field_file);
    struct_table_pointer->first_field = struct_table_pointer_temp->first_field;// 读出字段定义行

    // 把 .table 文件逆序列化到内存中
    struct_table_pointer_temp = connector_read_table(table_file);

    // 迁移
    struct_table_pointer->first_record = struct_table_pointer_temp->first_record;
    struct_table_pointer->record_counts = struct_table_pointer_temp->record_counts;

    return struct_table_pointer;
}

void table_in_disk_maintainer_insert_table(char *table_file, char *record) {

    bookworm_write_line(table_file, record);
}

void table_in_disk_maintainer_create_table(char *database_name, char *table_name, Struct_Table *struct_table_pointer) {

    char *table_file = grocery_concat_table_location_string(database_name, table_name);
    char *field_file = grocery_concat_table_field_location_string(database_name, table_name);
    char *frm_file = grocery_concat_table_frm_location_string(database_name, table_name);

    // 创建表
    connector_write_table(table_file, struct_table_pointer);
    connector_write_field(field_file, struct_table_pointer);
    connector_write_frm(frm_file, struct_table_pointer);
    // connector_write_index(file, struct_table_pointer); // 索引写入
}

FILE *table_in_disk_maintainer_show_tables(char *database_name, int delete) {

    // 用 ls 方法
    char shell[100];
    sprintf(shell, "cd %s && ls > ./temp_show_tables.txt", grocery_concat_database_location_string(database_name));
    // printf("shell:%s---------------\n", shell);
    system(shell);

    char file[100];
    sprintf(file, "%stemp_show_tables.txt", grocery_concat_database_location_string(database_name));
    FILE *fp = fopen(file, "r");
    if (NULL == fp) {
        grocery_exit_with_error("failed to open temp_show_tables.txt");
    }

    if (delete) {

        sprintf(shell, "rm %s", file);
        system(shell);
    }

    return fp;
}

/**
 * 删除数据表
 * @param database_name
 * @param table_name
 * @param infoschema_callback
 */
void table_in_disk_maintainer_drop_table(char *database_name, char *table_name, int infoschema_callback) {

    char *table_file = grocery_concat_table_location_string(database_name, table_name);
    char *table_frm_file = grocery_concat_table_frm_location_string(database_name, table_name);
    char *table_field_file = grocery_concat_table_field_location_string(database_name, table_name);
    char shell[300]; // 存在则忽略
    sprintf(shell, "rm %s && rm %s && rm %s", table_file, table_frm_file, table_field_file);
    system(shell);
}


