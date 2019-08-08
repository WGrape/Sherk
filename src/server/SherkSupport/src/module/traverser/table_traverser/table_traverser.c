#include <stdio.h>
#include <string.h>
#include <SherkSupport/src/include/serialize/tobe_serialized_structs.h>
#include <stdlib.h>
#include <SherkSupport/src/include/static/generator.h>
#include <sys/time.h>
#include <string.h>
#include <memory.h>
#include <SherkSupport/src/module/skeleton/skeleton.h>
#include <SherkService/test/module/test_table/test_table.h>

/**
 * 获取表结构信息(JSON格式)
 * @param struct_table_pointer
 * @return
 */
char *table_traverser_get_table_struct_json(Struct_Table *struct_table_pointer) {

    char *json = (char *) malloc(sizeof(char) * TABLE_STRUCT_JSON_MAX_LEN);
    char *format = "{\"id\":%d, "
                   "\"name\":\"%s\", \"engine\":%d, \"charset\":%d, "
                   "\"last_field\":\"%p\", \"first_field\":\"%p\", "
                   "\"last_record\":\"%p\", \"first_record\":\"%p\", "
                   "\"field_counts\":%d, \"record_counts\":%d, "
                   "\"database_name\":\"%s\", \"auto_increment\":%d, \"physical_location\":\"%s\"}";


    sprintf(json, format, struct_table_pointer->id,
            struct_table_pointer->name, struct_table_pointer->engine, struct_table_pointer->charset,
            struct_table_pointer->last_field, struct_table_pointer->first_field,
            struct_table_pointer->last_record, struct_table_pointer->first_record,
            struct_table_pointer->field_counts, struct_table_pointer->record_counts,
            struct_table_pointer->database_name, struct_table_pointer->auto_increment,
            struct_table_pointer->physical_location
    );

    return json;
}

/**
 * 获取一个字段(对象)
 * @param struct_field_pointer
 * @return
 */
Struct_Field table_traverser_get_a_field(Struct_Field *struct_field_pointer) {

    Struct_Field struct_field;
    struct_field.id = struct_field_pointer->id;
    struct_field.field_type = struct_field_pointer->field_type;
    struct_field.field_name = struct_field_pointer->field_name;

    struct_field.value_int = struct_field_pointer->value_int;
    struct_field.value_float = struct_field_pointer->value_float;
    struct_field.value_char = struct_field_pointer->value_char;
    struct_field.value_string = struct_field_pointer->value_string;

    struct_field.field_index = struct_field_pointer->field_index;
    struct_field.record_index = struct_field_pointer->record_index;
    struct_field.is_definition = struct_field_pointer->is_definition;
    struct_field.is_primary_key = struct_field_pointer->is_primary_key;

    struct_field.current = struct_field_pointer->current;
    struct_field.next = struct_field_pointer->next;
    struct_field.next_record = struct_field_pointer->next_record;

    struct_field.last = struct_field_pointer->last;
    struct_field.last_record = struct_field_pointer->last_record;

    return struct_field;
}

/**
 * 获取一个字段(JSON格式)
 * @param struct_field_pointer
 * @return
 */
char *table_traverser_get_a_field_json(Struct_Field *struct_field_pointer) {

    char *json = (char *) malloc(sizeof(char) * FIELD_JSON_MAX_LEN);
    char *format = "{\"id\":%d, \"field_type\":%d, \"field_name\":\"%s\", "
                   "\"value_int\":%d, \"value_float\":%f, \"value_string\":\"%s\", "
                   "\"field_index\":%d, \"record_index\":%d, \"is_definition\":%d, \"is_primary_key\":%d, "
                   "\"current\":\"%p\", \"next\":\"%p\", \"next_record\":\"%p\", "
                   "\"last\":\"%p\", \"last_record\":\"%p\"}";
    // 先不写字符: value_char:%c, 因为只要一写字符, 就出错, 出现 json 缺失的问题
    // char *format = "{id:%d, field_type:%d, field_name:%s, value_int:%d, value_float:%f, value_char:%c, value_string:%s, field_index:%d, record_index:%d, is_definition:%d, is_primary_key:%d, current:%p, next:%p, next_record:%p, last:%p, last_record:%p}";

    sprintf(json, format, struct_field_pointer->id, struct_field_pointer->field_type, struct_field_pointer->field_name,

            struct_field_pointer->value_int, struct_field_pointer->value_float,
            struct_field_pointer->value_string,

            struct_field_pointer->field_index, struct_field_pointer->record_index, struct_field_pointer->is_definition,
            struct_field_pointer->is_primary_key,

            struct_field_pointer->current, struct_field_pointer->next, struct_field_pointer->next_record,

            struct_field_pointer->last, struct_field_pointer->last_record
    );

    // printf("------json:%s,len:%d\n",json,strlen(json));

    return json;
}

/**
 * 获取一条记录的JSON格式
 * @param struct_field_pointer
 * @param count
 * @return
 */
char *table_traverser_get_a_record_json(Struct_Field *struct_field_pointer, int count) {

    int i;
    char *field_json, *record_json = (char *) (malloc(sizeof(char *) * RECORD_JSON_MAX_LEN));
    if (1 == count) {

        field_json = table_traverser_get_a_field_json(struct_field_pointer);

        strcpy(record_json, "[");
        strcat(record_json, field_json);
        strcat(record_json, "]");

    } else {
        for (i = 0; i <= count - 1 && NULL != struct_field_pointer; ++i) {

            field_json = table_traverser_get_a_field_json(struct_field_pointer);
            if (0 == i) {

                // 第一个字段
                strcpy(record_json, "[");
                strcat(record_json, field_json);
                strcat(record_json, ",");
            } else if (count - 1 == i) {

                // 最后一个字段
                strcat(record_json, field_json);
                strcat(record_json, "]");
            } else {

                strcat(record_json, field_json);
                strcat(record_json, ",");
            }
            // printf("---%s---\n",record_json);
            struct_field_pointer = struct_field_pointer->next;
        }
    }

    return record_json;
}

/**
 * 遍历一张表, 重新设置好index下标
 * @param struct_table_pointer
 */
void table_traverser_reset_index_in_order(Struct_Table *struct_table_pointer) {

    int field_index = 0, record_index = 0;

    // 先遍历表头
    Struct_Field *p = struct_table_pointer->first_field;
    p->field_index = field_index++;
    while (NULL != p->next) {

        p = p->next;
        p->field_index = field_index++;
    }

    // 再遍历表身
    int i, j, field_counts = struct_table_pointer->field_counts, record_counts = struct_table_pointer->field_counts;
    Struct_Field *p_i = struct_table_pointer->first_record;;
    Struct_Field *p_j = NULL;
    for (i = 1; i <= record_counts; ++i) {
        for (j = 1; j <= field_counts; ++j) {

            p_j->field_index = field_index++;
            p_j = p_j->next;
        }
        p_i = p_i->next_record;
        p_j = p_i;
        p_i->record_index = record_index++;
    }

}

/**
 * 查询一条记录
 * @param struct_table_pointer
 * @param id
 * @return
 */
Struct_Field *table_traverser_select_a_record(Struct_Table *struct_table_pointer, int id) {

}

