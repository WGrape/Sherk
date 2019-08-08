#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SherkSupport/src/include/serialize/tobe_serialized_structs.h>
#include <SherkSupport/src/module/maintainer/table_in_memory_maintainer/table_in_memory_maintainer.h>
#include <SherkSupport/src/module/maintainer/table_in_disk_maintainer/table_in_disk_maintainer.h>
#include <SherkSupport/src/module/skeleton/skeleton.h>
#include <SherkStorage/src/vendor/storage_serialization/module/bookworm/bookworm.h>


const int INFOSCHEMA_CALLBACK_ABLE = 1;
const int INFOSCHEMA_CALLBACK_DISABLE = 0;


// 回调, 所有的操作都是使用 table_maintainer, 这里不使用任何的 database_maintainer

char *infoschema_callback_get_system_table_location(int which_system_table) {

    if (WHICH_SYSTEM_TABLE_USERS == which_system_table) {

        return "/Users/yimutian/sherk/database/information_schema/users.table";
    } else if (WHICH_SYSTEM_TABLE_TABLES_MANAGE == which_system_table) {

        return "/Users/yimutian/sherk/database/information_schema/tables_manage.table";
    } else if (WHICH_SYSTEM_TABLE_DATABASES_MANAGE == which_system_table) {

        return "/Users/yimutian/sherk/database/information_schema/databases_manage.table";
    }

    return "";
}

// 返回插入的 id
int infoschema_callback_insert_record(char *table, Struct_Field **struct_fields_pointer) {

}

// 删除记录
void infoschema_callback_delete_record(char *table, int id) {


}

// 修改一条记录
void infoschema_callback_update_record(char *table) {


}

// 查询一条记录
void infoschema_callback_select_record(char *table, int id) {


}

void infoschema_callback_active(int id, char *database_name, char *table_name, char *user_name, char *password,
                                 char *encryption, char *time) {

    char *buffer = (char *) malloc(sizeof(char) * FIELD_JSON_MAX_LEN);

    if (0 == strcmp("users", table_name)) {

        // 创建4个字段, 分别是 id, name, password, time
        char *record_json = "["

                            // id 字段
                            "{\"id\":%d, \"field_type\":%d, \"field_name\":\"id\", \"value_int\":%d, \"value_float\":0.0, "
                            "\"value_string\":\"\", \"field_index\":0, \"record_index\":%d, \"is_definition\":0, "
                            "\"is_primary_key\":1,\"current\":\"NULL\",\"next\":\"NULL\", "
                            "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}, "

                            // name 字段
                            "{\"id\":%d, \"field_type\":%d, \"field_name\":\"name\", \"value_int\":0, \"value_float\":0.0, "
                            "\"value_string\":\"%s\", \"field_index\":1, \"record_index\":%d, \"is_definition\":0, "
                            "\"is_primary_key\":0,\"current\":\"NULL\",\"next\":\"NULL\", "
                            "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}, "

                            // password 字段
                            "{\"id\":%d, \"field_type\":%d, \"field_name\":\"password\", \"value_int\":0, \"value_float\":0.0, "
                            "\"value_string\":\"%s\", \"field_index\":2, \"record_index\":%d, \"is_definition\":0, "
                            "\"is_primary_key\":0,\"current\":\"NULL\",\"next\":\"NULL\", "
                            "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}, "

                            // time 字段
                            "{\"id\":%d, \"field_type\":%d, \"field_name\":\"time\", \"value_int\":0, \"value_float\":0.0, "
                            "\"value_string\":\"%s\", \"field_index\":3, \"record_index\":%d, \"is_definition\":0, "
                            "\"is_primary_key\":0,\"current\":\"NULL\",\"next\":\"NULL\", "
                            "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}"

                            "]\n";

        sprintf(buffer, record_json,
                id, FIELD_TYPE_INT, id, id,
                id, FIELD_TYPE_STRING, user_name, id,
                id, FIELD_TYPE_STRING, password, id,
                id, FIELD_TYPE_STRING, time, id
        );

        char *file = infoschema_callback_get_system_table_location(WHICH_SYSTEM_TABLE_USERS);
        bookworm_write_line(file, buffer);
    } else if (0 == strcmp("tables_manage", table_name)) {

        // 创建4个字段, 分别是 id, name, password, time
        char *record_json = "["

                            // id 字段
                            "{\"id\":%d, \"field_type\":%d, \"field_name\":\"id\", \"value_int\":%d, \"value_float\":0.0, "
                            "\"value_string\":\"\", \"field_index\":0, \"record_index\":%d, \"is_definition\":0, "
                            "\"is_primary_key\":1,\"current\":\"NULL\",\"next\":\"NULL\", "
                            "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}, "

                            // name 字段
                            "{\"id\":%d, \"field_type\":%d, \"field_name\":\"name\", \"value_int\":0, \"value_float\":0.0, "
                            "\"value_string\":\"%s\", \"field_index\":1, \"record_index\":%d, \"is_definition\":0, "
                            "\"is_primary_key\":0,\"current\":\"NULL\",\"next\":\"NULL\", "
                            "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}, "

                            // database 字段
                            "{\"id\":%d, \"field_type\":%d, \"field_name\":\"database\", \"value_int\":0, \"value_float\":0.0, "
                            "\"value_string\":\"%s\", \"field_index\":2, \"record_index\":%d, \"is_definition\":0, "
                            "\"is_primary_key\":0,\"current\":\"NULL\",\"next\":\"NULL\", "
                            "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}, "

                            // time 字段
                            "{\"id\":%d, \"field_type\":%d, \"field_name\":\"time\", \"value_int\":0, \"value_float\":0.0, "
                            "\"value_string\":\"%s\", \"field_index\":3, \"record_index\":%d, \"is_definition\":0, "
                            "\"is_primary_key\":0,\"current\":\"NULL\",\"next\":\"NULL\", "
                            "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}"

                            "]\n";

        sprintf(buffer, record_json,
                id, FIELD_TYPE_INT, id, id,
                id, FIELD_TYPE_STRING, table_name, id,
                id, FIELD_TYPE_STRING, database_name, id,
                id, FIELD_TYPE_STRING, time, id
        );

        char *file = infoschema_callback_get_system_table_location(WHICH_SYSTEM_TABLE_TABLES_MANAGE);
        bookworm_write_line(file, buffer);
    } else if (0 == strcmp("databases_manage", table_name)) {

        // 创建4个字段, 分别是 id, name, password, time
        char *record_json = "["

                            // id 字段
                            "{\"id\":%d, \"field_type\":%d, \"field_name\":\"id\", \"value_int\":%d, \"value_float\":0.0, "
                            "\"value_string\":\"\", \"field_index\":0, \"record_index\":%d, \"is_definition\":0, "
                            "\"is_primary_key\":1,\"current\":\"NULL\",\"next\":\"NULL\", "
                            "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}, "

                            // name 字段
                            "{\"id\":%d, \"field_type\":%d, \"field_name\":\"name\", \"value_int\":0, \"value_float\":0.0, "
                            "\"value_string\":\"%s\", \"field_index\":1, \"record_index\":%d, \"is_definition\":0, "
                            "\"is_primary_key\":0,\"current\":\"NULL\",\"next\":\"NULL\", "
                            "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}, "

                            // time 字段
                            "{\"id\":%d, \"field_type\":%d, \"field_name\":\"time\", \"value_int\":0, \"value_float\":0.0, "
                            "\"value_string\":\"%s\", \"field_index\":3, \"record_index\":%d, \"is_definition\":0, "
                            "\"is_primary_key\":0,\"current\":\"NULL\",\"next\":\"NULL\", "
                            "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}, "

                            // encryption 字段
                            "{\"id\":%d, \"field_type\":%d, \"field_name\":\"encryption\", \"value_int\":0, \"value_float\":0.0, "
                            "\"value_string\":\"%s\", \"field_index\":2, \"record_index\":%d, \"is_definition\":0, "
                            "\"is_primary_key\":0,\"current\":\"NULL\",\"next\":\"NULL\", "
                            "\"next_record\":\"NULL\", \"last\":\"NULL\", \"last_record\":\"NULL\"}"

                            "]\n";

        sprintf(buffer, record_json,
                id, FIELD_TYPE_INT, id, id,
                id, FIELD_TYPE_STRING, database_name, id,
                id, FIELD_TYPE_STRING, time, id,
                id, FIELD_TYPE_STRING, encryption, id
        );

        char *file = infoschema_callback_get_system_table_location(WHICH_SYSTEM_TABLE_DATABASES_MANAGE);
        // printf("------------buffer:%s,-------------file:%s-----------\n",buffer, file);
        bookworm_write_line(file, buffer);
    }

}



