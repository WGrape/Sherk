#include <stdio.h>
#include <SherkSupport/src/include/serialize/tobe_serialized_structs.h>
#include <stdlib.h>
#include <SherkSupport/src/include/static/generator.h>
#include <sys/time.h>
#include <string.h>
#include <memory.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <SherkSupport/src/module/skeleton/skeleton.h>
#include <SherkService/test/module/test_table/test_table.h>
#include <SherkStorage/src/vendor/storage_serialization/module/loyal_serializer/loyal_serializer.h>


void table_in_memory_maintainer_drop_table(char *database_name, char *table_name, int infoschema_callback) {

}

/**
 * 暂时不用
 * @param struct_table_pointer_src
 * @param struct_table_pointer_dist
 */
void table_in_memory_maintainer_cp_struct_table_pointer(Struct_Table *struct_table_pointer_src,
                                                        Struct_Table *struct_table_pointer_dist) {

    struct_table_pointer_dist->first_field = struct_table_pointer_src->first_field;
    struct_table_pointer_dist->id = struct_table_pointer_src->id;
    struct_table_pointer_dist->name = struct_table_pointer_src->name;
    struct_table_pointer_dist->first_record = struct_table_pointer_src->first_record;
    struct_table_pointer_dist->last_field = struct_table_pointer_src->last_field;
    struct_table_pointer_dist->last_record = struct_table_pointer_src->last_record;
    struct_table_pointer_dist->field_counts = struct_table_pointer_src->field_counts;
    struct_table_pointer_dist->record_counts = struct_table_pointer_src->record_counts;
    struct_table_pointer_dist->database_name = struct_table_pointer_src->database_name;
}

/**
 * 创建一个字段
 * @param struct_field_pointer
 * @param field_type
 * @param field_name
 * @param field_index
 * @param is_definition
 * @param is_primary_key
 * @return
 */
Struct_Field *
table_in_memory_maintainer_create_a_field(Struct_Field *struct_field_pointer, int field_type, char *field_name,
                                          int field_index, int is_definition,
                                          int is_primary_key) {

    struct_field_pointer->id = generator_field_id++;
    struct_field_pointer->field_type = field_type;
    struct_field_pointer->field_name = field_name;


    struct_field_pointer->field_index = field_index;
    struct_field_pointer->is_definition = is_definition;
    struct_field_pointer->is_primary_key = is_primary_key;

    struct_field_pointer->current = struct_field_pointer;
    struct_field_pointer->next = NULL;
    struct_field_pointer->last_record = NULL;
    struct_field_pointer->next_record = NULL;

    if (is_definition) {

        struct_field_pointer->field_type = FIELD_TYPE_DEFINITION;
    }

    return struct_field_pointer;
}


/**
 * 创建一个表
 * @param name
 * @param auto_increment
 * @param engine
 * @param charset
 * @return Struct_Table *
 */
Struct_Table *
table_in_memory_maintainer_create_a_table(char *database_name, char *name, int auto_increment, int engine,
                                          int charset) {

    Struct_Table *struct_table_pointer = (Struct_Table *) malloc(sizeof(Struct_Table) * 1);

    struct_table_pointer->id = generator_table_id++;
    struct_table_pointer->name = name;
    struct_table_pointer->database_name = database_name;

    struct_table_pointer->physical_location = grocery_concat_table_location_string(database_name, name);

    struct_table_pointer->field_counts = 0;
    struct_table_pointer->record_counts = 0;
    struct_table_pointer->auto_increment = auto_increment;
    struct_table_pointer->engine = engine;
    struct_table_pointer->charset = charset;

    struct_table_pointer->first_field = NULL; // 第一个字段
    struct_table_pointer->last_field = NULL; // 最后一个字段
    struct_table_pointer->first_record = NULL; // 第一条记录
    struct_table_pointer->last_record = NULL; // 最后一条记录

    return struct_table_pointer;
}

/**
 * 创建一个表 - 临时操作
 * @return
 */
Struct_Table *
table_in_memory_maintainer_create_a_table_temp() {

    return table_in_memory_maintainer_create_a_table("", "", 0, 0, 0);
}

/**
 * 创建一个表定义字段
 * @param field_type
 * @param field_name
 * @param field_index
 * @param is_definition
 * @param is_primary_key
 * @return
 */
Struct_Field *
table_in_memory_maintainer_create_a_field_definition(int field_type,
                                                     char *field_name,
                                                     int field_index, int is_definition,
                                                     int is_primary_key) {

    Struct_Field *struct_field_pointer = (Struct_Field *) malloc(sizeof(Struct_Field) * 1);
    struct_field_pointer->value_int = 0;
    struct_field_pointer->value_float = 0.0;
    struct_field_pointer->value_char = '0'; // \0 无法输出, 故以'0'代替
    struct_field_pointer->value_string = "\0";

    return table_in_memory_maintainer_create_a_field(struct_field_pointer, field_type, field_name,
                                                     field_index,
                                                     is_definition, is_primary_key);
}

/**
 * 创建一个整型字段
 * @param field_type
 * @param field_name
 * @param value_int
 * @param field_index
 * @param is_definition
 * @param is_primary_key
 * @return
 */
Struct_Field *
table_in_memory_maintainer_create_a_field_int(int field_type,
                                              char *field_name,
                                              int value_int,
                                              int field_index, int is_definition,
                                              int is_primary_key) {

    Struct_Field *struct_field_pointer = (Struct_Field *) malloc(sizeof(Struct_Field) * 1);
    struct_field_pointer->value_int = value_int;
    struct_field_pointer->value_float = 0.0;
    struct_field_pointer->value_char = '0'; // \0 无法输出, 故以'0'代替
    struct_field_pointer->value_string = "\0";

    return table_in_memory_maintainer_create_a_field(struct_field_pointer, field_type, field_name,
                                                     field_index,
                                                     is_definition, is_primary_key);
}

/**
 * 创建一个浮点型字段
 * @param struct_table_pointer
 * @param last
 * @param field_type
 * @param field_name
 * @param value_float
 * @param field_index
 * @param is_definition
 * @param is_primary_key
 * @return
 */
Struct_Field *
table_in_memory_maintainer_create_a_field_float(int field_type,
                                                char *field_name,
                                                float value_float,
                                                int field_index, int is_definition,
                                                int is_primary_key) {

    Struct_Field *struct_field_pointer = (Struct_Field *) malloc(sizeof(Struct_Field) * 1);
    struct_field_pointer->value_float = value_float;
    struct_field_pointer->value_int = 0;
    struct_field_pointer->value_char = '\0';
    struct_field_pointer->value_string = "\0";

    return table_in_memory_maintainer_create_a_field(struct_field_pointer, field_type, field_name,
                                                     field_index,
                                                     is_definition, is_primary_key);
}

/**
 * 创建一个字符型字段
 * @param struct_table_pointer
 * @param last
 * @param field_type
 * @param field_name
 * @param value_char
 * @param field_index
 * @param is_definition
 * @param is_primary_key
 * @return
 */
Struct_Field *
table_in_memory_maintainer_create_a_field_char(int field_type,
                                               char *field_name,
                                               char value_char,
                                               int field_index, int is_definition,
                                               int is_primary_key) {

    Struct_Field *struct_field_pointer = (Struct_Field *) malloc(sizeof(Struct_Field) * 1);
    struct_field_pointer->value_char = value_char;
    struct_field_pointer->value_float = 0.0;
    struct_field_pointer->value_int = 0;
    struct_field_pointer->value_string = "\0";

    return table_in_memory_maintainer_create_a_field(struct_field_pointer, field_type, field_name,
                                                     field_index,
                                                     is_definition, is_primary_key);
}

/**
 * 创建一个字符串类型字段
 * @param struct_table_pointer
 * @param last
 * @param field_type
 * @param field_name
 * @param value_string
 * @param field_index
 * @param is_definition
 * @param is_primary_key
 * @return
 */
Struct_Field *
table_in_memory_maintainer_create_a_field_string(int field_type,
                                                 char *field_name,
                                                 char *value_string,
                                                 int field_index, int is_definition,
                                                 int is_primary_key) {

    Struct_Field *struct_field_pointer = (Struct_Field *) malloc(sizeof(Struct_Field) * 1);
    struct_field_pointer->value_string = value_string;
    struct_field_pointer->value_char = '\0';
    struct_field_pointer->value_float = 0.0;
    struct_field_pointer->value_int = 0;

    return table_in_memory_maintainer_create_a_field(struct_field_pointer, field_type, field_name,
                                                     field_index,
                                                     is_definition, is_primary_key);
}

void table_in_memory_maintainer_insert_table_head(Struct_Table *struct_table_pointer,
                                                  Struct_Field *struct_table_head_pointer) {

    struct_table_pointer->first_field = struct_table_head_pointer;
}

/**
 * 插入一条记录
 * @param struct_table_pointer
 * @param struct_field_pointer
 */
void
table_in_memory_maintainer_insert_a_record(Struct_Table *struct_table_pointer, Struct_Field *struct_record_pointer) {


    if (NULL == struct_table_pointer->first_record) {

        // 如果当前记录为空
        struct_table_pointer->first_record = struct_record_pointer;
    } else {

        Struct_Field *record_pointer = struct_table_pointer->first_record; // 指向第一条记录

        // 如果还有下一条记录
        while (NULL != record_pointer->next_record) {
            record_pointer = record_pointer->next_record;
        }
        record_pointer->next_record = struct_record_pointer;
    }

    struct_table_pointer->record_counts += 1;

    struct_record_pointer->record_index = struct_table_pointer->record_counts;
    struct_record_pointer->next_record = NULL;

    struct_table_pointer->last_record = struct_record_pointer;
}

/**
 * 删除一条记录
 * @param struct_table_pointer
 * @param struct_field_pointer
 */
void table_in_memory_maintainer_delete_a_record(Struct_Table *struct_table_pointer, int id) {

    // 是否指针指向的内存
}

/**
 * 更新一条记录
 * @param struct_table_pointer
 * @param id
 * @param record_pointer
 */
//void table_in_memory_maintainer_update_a_record(Struct_Table *struct_table_pointer, int id,
//                                                Struct_Field *record_pointer) {
// 找到目标记录的时候, 进行指针替换, 并删除过期指针, 实现更新效果
//}


void table_in_memory_maintainer_update_a_record(char *file, Struct_Table *struct_table_pointer, int field_count,
                                                char **field_name_list, int *field_type_list,
                                                int *field_value_int,
                                                float *field_value_float, char *field_value_char,
                                                char **field_value_string, char *column, int id) {

    int i, record_count = struct_table_pointer->record_counts;
    Struct_Field *record_pointer = struct_table_pointer->first_record;
    for (i = 1; i <= record_count; ++i) {

        if (id == i) {

            Struct_Field *field_pointer = record_pointer;
            while (NULL != field_pointer) {

                // 判断当前遍历的字段是否存在于field_name_list中
                int index = grocery_string_item_in_array_index(field_name_list, field_pointer->field_name, field_count);
                // printf("\n----------");printf("index:%d,field_name:%s\n",index,field_pointer->field_name);
                if (-1 < index) {

                    if (FIELD_TYPE_INT == field_type_list[index]) {

                        field_pointer->value_int = field_value_int[index];
                    } else if (FIELD_TYPE_FLOAT == field_type_list[index]) {

                        field_pointer->value_float = field_value_float[index];
                    } else if (FIELD_TYPE_CHAR == field_type_list[index]) {

                        field_pointer->value_char = field_value_char[index];
                    } else {

                        char *new_value2 = (char *) malloc(sizeof(char) * 20);
                        strcpy(new_value2, field_value_string[index]);
                        field_pointer->value_string = new_value2;
                    }
                }

                field_pointer = field_pointer->next;
            }

            break;
        }
        record_pointer = record_pointer->next_record;
    }

    // test_table_print_table_info(struct_table_pointer);
    loyal_serializer_serialize_table(struct_table_pointer, file);
}

/**
 * 追加一个字段
 * @param struct_field_pointer
 */
void table_in_memory_maintainer_append_a_field(Struct_Field *last_field_pointer, Struct_Field *struct_field_pointer) {

    last_field_pointer->next = struct_field_pointer;
}

/**
 * 创建表头
 * @param struct_table_pointer
 * @param field_name_list
 * @param field_type_list
 * @param field_count
 * @return
 */
Struct_Field *table_in_memory_maintainer_create_table_head(Struct_Table *struct_table_pointer, char **field_name_list,
                                                           const int *field_type_list, int field_count) {

    // 初始化
    Struct_Field *first_field_pointer = NULL;
    Struct_Field *last_field_pointer = NULL;
    Struct_Field *current_field_pointer = NULL;

    // 遍历创建表头字段
    for (int j = 0; j <= field_count - 1; ++j) {

        // 值都是随意生成的, 无所谓, 因为这是定义字段, 不是数据字段

        if (FIELD_TYPE_INT == field_type_list[j]) {

            current_field_pointer = table_in_memory_maintainer_create_a_field_int(FIELD_TYPE_INT, field_name_list[j],
                                                                                  76, j, 1, j == 0);
        } else if (FIELD_TYPE_FLOAT == field_type_list[j]) {

            current_field_pointer = table_in_memory_maintainer_create_a_field_float(FIELD_TYPE_FLOAT,
                                                                                    field_name_list[j], 15.4, j, 1,
                                                                                    j == 0);
        } else if (FIELD_TYPE_CHAR == field_type_list[j]) {

            current_field_pointer = table_in_memory_maintainer_create_a_field_char(FIELD_TYPE_CHAR, field_name_list[j],
                                                                                   'a', j, 1, j == 0);
        } else {

            current_field_pointer = table_in_memory_maintainer_create_a_field_string(FIELD_TYPE_STRING,
                                                                                     field_name_list[j], "ds", j, 1,
                                                                                     j == 0);
        }

        if (0 == j) {

            first_field_pointer = current_field_pointer;
        } else {

            table_in_memory_maintainer_append_a_field(last_field_pointer, current_field_pointer);
        }

        last_field_pointer = current_field_pointer;
    }

    struct_table_pointer->field_counts = field_count;
    struct_table_pointer->last_field = current_field_pointer;
    table_in_memory_maintainer_insert_table_head(struct_table_pointer, first_field_pointer);

    return first_field_pointer;
}


