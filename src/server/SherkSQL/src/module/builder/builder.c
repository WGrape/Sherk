#include <stdio.h>
#include <SherkSupport/src/module/skeleton/skeleton.h>
#include <SherkSupport/src/module/maintainer/table_in_memory_maintainer/table_in_memory_maintainer.h>
#include <SherkSupport/src/module/traverser/table_traverser/table_traverser.h>

char *
builder_generate_record_json(int field_count, char **field_name_list, int *field_type_list, int *field_value_int,
                             float *field_value_float, char *field_value_char, char **field_value_string) {


    int i;
    Struct_Field *first_field_pointer = NULL;
    Struct_Field *last_field_pointer = NULL;
    Struct_Field *current_field_pointer = NULL;

    for (i = 0; i <= field_count - 1; ++i) {

        if (FIELD_TYPE_INT == field_type_list[i]) {

            current_field_pointer = table_in_memory_maintainer_create_a_field_int(FIELD_TYPE_INT, field_name_list[i],
                                                                                  field_value_int[i], i, 0,
                                                                                  0 == i);
        } else if (FIELD_TYPE_FLOAT == field_type_list[i]) {

            current_field_pointer = table_in_memory_maintainer_create_a_field_float(FIELD_TYPE_FLOAT,
                                                                                    field_name_list[i],
                                                                                    field_value_float[i],
                                                                                    i, 0,
                                                                                    0 == i);
        } else if (FIELD_TYPE_CHAR == field_type_list[i]) {

            current_field_pointer = table_in_memory_maintainer_create_a_field_char(FIELD_TYPE_CHAR, field_name_list[i],
                                                                                   field_value_char[i],
                                                                                   i, 0,
                                                                                   0 == i);
        } else {


            current_field_pointer = table_in_memory_maintainer_create_a_field_string(FIELD_TYPE_STRING,
                                                                                     field_name_list[i],
                                                                                     field_value_string[i],
                                                                                     i, 0,
                                                                                     0 == i);
        }

        if (0 == i) {

            first_field_pointer = current_field_pointer;
        } else {

            table_in_memory_maintainer_append_a_field(last_field_pointer, current_field_pointer);
        }

        last_field_pointer = current_field_pointer;
    }

    return table_traverser_get_a_record_json(first_field_pointer, field_count);
}