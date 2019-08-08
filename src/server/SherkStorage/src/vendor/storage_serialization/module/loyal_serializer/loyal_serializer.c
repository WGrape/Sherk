#include <stdio.h>
#include <msgpack.h>
#include <SherkSupport/src/include/serialize/tobe_serialized_structs.h>
#include <SherkSupport/src/module/skeleton/skeleton.h>
#include <SherkSupport/src/module/traverser/table_traverser/table_traverser.h>
#include <SherkService/test/module/test_table/test_table.h>
#include <SherkSupport/src/vendor/cJSON/cJSON.h>
#include <SherkSupport/src/module/maintainer/table_in_memory_maintainer/table_in_memory_maintainer.h>
#include <SherkStorage/src/vendor/storage_serialization/module/bookworm/bookworm.h>

/**
 * 将数据表的字段文件序列化到磁盘上
 * @param struct_table_pointer
 * @param file
 */
void loyal_serializer_serialize_field(Struct_Table *struct_table_pointer, char *field_file) {

    // 循环初始化
    int i, j;
    int field_counts = struct_table_pointer->field_counts;

    // json 和 字段对象 初始化
    char field_json[FIELD_JSON_MAX_LEN];
    char record_json[RECORD_JSON_MAX_LEN];
    memset(record_json, '\0', sizeof(char) * RECORD_JSON_MAX_LEN);

    // 记录每条记录的信息, 开始循环
    Struct_Field *field_pointer = struct_table_pointer->first_field;
    bookworm_write(field_file, ""); // 先清空文件内容

    for (j = 0; j <= field_counts - 1; ++j) {

        memset(field_json, '\0', sizeof(char) * FIELD_JSON_MAX_LEN);

        strcpy(field_json, table_traverser_get_a_field_json(field_pointer));
        field_pointer = field_pointer->next;

        if (field_counts - 1 != j) {

            strcat(field_json, ", \n");
        }
        strcat(record_json, field_json);
    }
    bookworm_write(field_file, record_json); // 一条记录一条记录的写入
}

/**
 * 将磁盘上的数据表的字段文件反序列化到内存中
 * @param field_file
 * @return
 */
Struct_Table *loyal_serializer_unserialize_field(char *field_file) {

    int j;
    char *record = NULL;


    Struct_Field *last_field_pointer = NULL;
    Struct_Field *current_field_pointer = NULL;
    Struct_Table *struct_table_pointer = table_in_memory_maintainer_create_a_table_temp();
    for (j = 1;; ++j) {

        record = bookworm_read_x_line(field_file, j);
        if (NULL == record) {
            break;
        }

        cJSON *json;
        json = cJSON_Parse(record); //获取整个大的句柄

        int id = (cJSON_GetObjectItem(json, "id"))->valueint;
        int field_type = (cJSON_GetObjectItem(json, "field_type"))->valueint;
        int field_index = (cJSON_GetObjectItem(json, "field_index"))->valueint;
        int is_definition = (cJSON_GetObjectItem(json, "is_definition"))->valueint;
        int is_primary_key = (cJSON_GetObjectItem(json, "is_primary_key"))->valueint;
        char *field_name = (cJSON_GetObjectItem(json, "field_name"))->valuestring;

        current_field_pointer = table_in_memory_maintainer_create_a_field_definition(field_type,
                                                                                     field_name,
                                                                                     field_index,
                                                                                     is_definition,
                                                                                     is_primary_key);
        if (1 == j) {

            table_in_memory_maintainer_insert_table_head(struct_table_pointer, current_field_pointer);
        } else {

            table_in_memory_maintainer_append_a_field(last_field_pointer, current_field_pointer);
        }

        last_field_pointer = current_field_pointer;
    }

    return struct_table_pointer;
}

/**
 * 将数据表的数据文件序列化到磁盘中
 * @param struct_table_pointer
 * @param file
 */
void loyal_serializer_serialize_table(Struct_Table *struct_table_pointer, char *file) {

    // 循环初始化
    int i, j;
    int record_counts = struct_table_pointer->record_counts;
    int field_counts = struct_table_pointer->field_counts;

    // json 和 字段对象 初始化
    char field_json[FIELD_JSON_MAX_LEN];
    char record_json[RECORD_JSON_MAX_LEN];

    // 记录每条记录的信息, 开始循环
    Struct_Field *field_pointer = struct_table_pointer->first_record;
    Struct_Field *record_pointer = field_pointer;
    bookworm_write(file, ""); // 先清空文件内容
    for (i = 1; i <= record_counts && NULL != record_pointer; ++i) {

        memset(record_json, '\0', sizeof(char) * RECORD_JSON_MAX_LEN);
        for (j = 0; j <= field_counts - 1 && NULL != field_pointer; ++j) {

            memset(field_json, '\0', sizeof(char) * FIELD_JSON_MAX_LEN);

            // 如果是第1个
            if (0 == j) {

                strcat(field_json, "[");
            }

            strcat(field_json, table_traverser_get_a_field_json(field_pointer));
            field_pointer = field_pointer->next;

            if (field_counts - 1 != j) {

                strcat(field_json, ", ");
            } else {

                strcat(field_json, "]");
            }
            strcat(record_json, field_json);
        }
        record_pointer = record_pointer->next_record; // 每一行记录的第一个字段
        field_pointer = record_pointer;
        strcat(record_json, "\n");
        bookworm_write_line(file, record_json); // 一条记录一条记录的写入
    }
}

/**
 * 将数据表文件从磁盘中逆序列化出来到内存中
 * @param table_physical_location
 * @return
 */
Struct_Table *loyal_serializer_unserialize_table(char *table) {

    int i, j;
    char *record = NULL;


    Struct_Field *last_field_pointer = NULL;
    Struct_Field *current_field_pointer = NULL;
    Struct_Field *record_pointer = NULL;
    Struct_Table *struct_table_pointer = table_in_memory_maintainer_create_a_table_temp();
    struct_table_pointer->record_counts = 0;
    for (i = 1;; ++i) {

        // 记录为空
        record = bookworm_read_x_line(table, i);
        if (NULL == record) { break; }

        // 给记录计数
        ++(struct_table_pointer->record_counts);

        cJSON *field_array = cJSON_Parse(record); //获取整个大的句柄
        if (NULL == field_array) { continue; }


        cJSON *field = field_array->child;
        j = 1;
        while (field != NULL) {

            int id = (cJSON_GetObjectItem(field, "id"))->valueint;
            int field_type = (cJSON_GetObjectItem(field, "field_type"))->valueint;
            int field_index = (cJSON_GetObjectItem(field, "field_index"))->valueint;
            int is_definition = (cJSON_GetObjectItem(field, "is_definition"))->valueint;
            int is_primary_key = (cJSON_GetObjectItem(field, "is_primary_key"))->valueint;
            char *field_name = (cJSON_GetObjectItem(field, "field_name"))->valuestring;

            int value_int = (cJSON_GetObjectItem(field, "value_int"))->valueint;
            double value_float = (cJSON_GetObjectItem(field, "value_float"))->valuedouble;
            char *value_string = (cJSON_GetObjectItem(field, "value_string"))->valuestring;

            current_field_pointer = table_in_memory_maintainer_create_a_field_definition(field_type,
                                                                                         field_name,
                                                                                         field_index,
                                                                                         is_definition,
                                                                                         is_primary_key);

            current_field_pointer->id=id;
            current_field_pointer->value_char = '\0';
            current_field_pointer->value_int = value_int;
            current_field_pointer->value_float = (float)value_float;
            current_field_pointer->value_string = value_string;

            if (1 == j) {

                record_pointer = current_field_pointer;
            } else {

                table_in_memory_maintainer_append_a_field(last_field_pointer, current_field_pointer);
            }

            last_field_pointer = current_field_pointer;

            field = field->next;
            ++j;
        }

        table_in_memory_maintainer_insert_a_record(struct_table_pointer, record_pointer);
    }

    return struct_table_pointer;
}

/**
 * 将数据表的表结构信息序列化到磁盘上
 * @param struct_table_pointer
 * @param file
 */
void loyal_serializer_serialize_frm(Struct_Table *struct_table_pointer, char *file) {

    // 创建数据表的表结构文件( 记录到 frm 文件中 )
    bookworm_write(file,
                   table_traverser_get_table_struct_json(struct_table_pointer));
}

/**
 * 将数据表定义文件从磁盘中逆序列化出来到内存中
 * @param table_physical_location
 * @return
 */
Struct_Table *loyal_serializer_unserialize_frm(char *frm_file) {

    FILE *fp = fopen(frm_file, "r");

    char *record = (char *) malloc(sizeof(char) * FIELD_JSON_MAX_LEN);
    fgets(record, FIELD_JSON_MAX_LEN, fp);
    fclose(fp);


    cJSON *json;
    json = cJSON_Parse(record); //获取整个大的句柄
    // printf("-------%s\n-------", cJSON_Print(json));  //这个是可以输出的。为获取的整个json的值

    char *database_name = (cJSON_GetObjectItem(json, "database_name"))->valuestring;
    char *name = (cJSON_GetObjectItem(json, "name"))->valuestring;
    char *physical_location = (cJSON_GetObjectItem(json, "physical_location"))->valuestring;

    char *first_field = (cJSON_GetObjectItem(json, "first_field"))->valuestring;
    char *last_field = (cJSON_GetObjectItem(json, "last_field"))->valuestring;
    char *first_record = (cJSON_GetObjectItem(json, "first_record"))->valuestring;
    char *last_record = (cJSON_GetObjectItem(json, "last_record"))->valuestring;

    int auto_increment = (cJSON_GetObjectItem(json, "auto_increment"))->valueint;
    int engine = (cJSON_GetObjectItem(json, "engine"))->valueint;
    int charset = (cJSON_GetObjectItem(json, "charset"))->valueint;
    int id = (cJSON_GetObjectItem(json, "id"))->valueint;
    int field_counts = (cJSON_GetObjectItem(json, "field_counts"))->valueint;
    int record_counts = (cJSON_GetObjectItem(json, "record_counts"))->valueint;

    Struct_Table *struct_table_pointer = table_in_memory_maintainer_create_a_table(database_name, name, auto_increment,
                                                                                   engine, charset);

    struct_table_pointer->id = id;
    struct_table_pointer->field_counts = field_counts;
    struct_table_pointer->record_counts = record_counts;
    struct_table_pointer->physical_location = physical_location;

    // 这里的地址和存储在 frm 文件中的地址匹配不上, 是因为强转化的问题, 日后修改
    struct_table_pointer->first_field = (Struct_Field *) first_field;
    struct_table_pointer->last_field = (Struct_Field *) last_field;
    struct_table_pointer->first_record = (Struct_Field *) first_record;
    struct_table_pointer->last_record = (Struct_Field *) last_record;

    return struct_table_pointer;
}



