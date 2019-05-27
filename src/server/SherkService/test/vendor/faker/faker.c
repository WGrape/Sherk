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

}