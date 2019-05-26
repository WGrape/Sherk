#include <stdio.h>
#include <stdlib.h>

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