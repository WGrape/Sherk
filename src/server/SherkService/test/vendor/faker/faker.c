#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SherkSupport/src/module/maintainer/table_in_memory_maintainer/table_in_memory_maintainer.h>
#include <SherkSupport/src/module/skeleton/skeleton.h>

char **faker_get_field_name_list(int case_id) {

    char **field_name_list = (char **) malloc(sizeof(char *) * 3);

    if (1 == case_id) {

        field_name_list[0] = "name";
        field_name_list[1] = "age";
        field_name_list[2] = "sex";
    } else if (2 == case_id) {

        field_name_list[0] = "column_1";
        field_name_list[1] = "column_2";
        field_name_list[2] = "column_3";
    }

    return field_name_list;
}

char **faker_get_field_type_list(int case_id) {


}

char *faker_simulate_a_record_json(int id, char *table_name) {

    char *buffer = (char *) malloc(sizeof(char) * FIELD_JSON_MAX_LEN);

    char *record_json = "["

                        // id 字段
                        "{\"id\":%d, \"field_type\":%d, \"field_name\":\"id\", \"value_int\":%d, \"value_float\":0.0, "
                        "\"value_string\":\"\", \"field_index\":0, \"record_index\":%d, \"is_definition\":0, "
                        "\"is_primary_key\":1,\"current\":\"NULL\",\"next\":\"NULL\", "
                        "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}, "

                        // name 字段
                        "{\"id\":%d, \"field_type\":%d, \"field_name\":\"name\", \"value_int\":0, \"value_float\":0.0, "
                        "\"value_string\":\"一个新人\", \"field_index\":1, \"record_index\":%d, \"is_definition\":0, "
                        "\"is_primary_key\":0,\"current\":\"NULL\",\"next\":\"NULL\", "
                        "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}, "

                        // age 字段
                        "{\"id\":%d, \"field_type\":%d, \"field_name\":\"age\", \"value_int\":0, \"value_float\":0.0, "
                        "\"value_string\":\"\", \"field_index\":2, \"record_index\":%d, \"is_definition\":0, "
                        "\"is_primary_key\":0,\"current\":\"NULL\",\"next\":\"NULL\", "
                        "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}, "

                        // sex 字段
                        "{\"id\":%d, \"field_type\":%d, \"field_name\":\"sex\", \"value_int\":0, \"value_float\":0.0, "
                        "\"value_string\":\"\", \"field_index\":3, \"record_index\":%d, \"is_definition\":0, "
                        "\"is_primary_key\":0,\"current\":\"NULL\",\"next\":\"NULL\", "
                        "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}"

                        "]\n";

    sprintf(buffer, record_json,
            id, FIELD_TYPE_INT, id, id,
            id, FIELD_TYPE_STRING, id,
            id, FIELD_TYPE_STRING, id,
            id, FIELD_TYPE_STRING, id
    );

    return buffer;
}

char *faker_simulate_a_record_update_json(int id, char *table_name) {

    char *buffer = (char *) malloc(sizeof(char) * FIELD_JSON_MAX_LEN);

    char *record_json = "["

                        // id 字段
                        "{\"id\":%d, \"field_type\":%d, \"field_name\":\"id\", \"value_int\":%d, \"value_float\":0.0, "
                        "\"value_string\":\"\", \"field_index\":0, \"record_index\":%d, \"is_definition\":0, "
                        "\"is_primary_key\":1,\"current\":\"NULL\",\"next\":\"NULL\", "
                        "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}, "

                        // name 字段
                        "{\"id\":%d, \"field_type\":%d, \"field_name\":\"name\", \"value_int\":0, \"value_float\":0.0, "
                        "\"value_string\":\"name被修改\", \"field_index\":1, \"record_index\":%d, \"is_definition\":0, "
                        "\"is_primary_key\":0,\"current\":\"NULL\",\"next\":\"NULL\", "
                        "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}, "

                        // age 字段
                        "{\"id\":%d, \"field_type\":%d, \"field_name\":\"age\", \"value_int\":0, \"value_float\":0.0, "
                        "\"value_string\":\"age被修改\", \"field_index\":2, \"record_index\":%d, \"is_definition\":0, "
                        "\"is_primary_key\":0,\"current\":\"NULL\",\"next\":\"NULL\", "
                        "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}, "

                        // sex 字段
                        "{\"id\":%d, \"field_type\":%d, \"field_name\":\"sex\", \"value_int\":0, \"value_float\":0.0, "
                        "\"value_string\":\"\", \"field_index\":3, \"record_index\":%d, \"is_definition\":0, "
                        "\"is_primary_key\":0,\"current\":\"NULL\",\"next\":\"NULL\", "
                        "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}"

                        "]\n";

    sprintf(buffer, record_json,
            id, FIELD_TYPE_INT, id, id,
            id, FIELD_TYPE_STRING, id,
            id, FIELD_TYPE_STRING, id,
            id, FIELD_TYPE_STRING, id
    );

    return buffer;
}



