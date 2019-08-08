#include <stdio.h>
#include <SherkSupport/src/include/serialize/tobe_serialized_structs.h>
#include <stdlib.h>
#include <SherkSupport/src/include/static/generator.h>
#include <sys/time.h>
#include <string.h>
#include <memory.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <SherkSupport/src/module/skeleton/skeleton.h>
#include <SherkService/mechanism/include/define/color.h>


/**
 * 打印字段的信息
 * @param struct_field_pointer
 */
void table_painter_print_table_field_info(Struct_Field *struct_field_pointer) {

    printf(BLUE);
    if (struct_field_pointer->is_definition) {

        printf("| %s ", struct_field_pointer->field_name);
    } else {

        if (FIELD_TYPE_INT == struct_field_pointer->field_type) {

            printf("| %d ", struct_field_pointer->value_int);
        } else if (FIELD_TYPE_FLOAT == struct_field_pointer->field_type) {

            printf("| %f ", struct_field_pointer->value_float);
        } else if (FIELD_TYPE_CHAR == struct_field_pointer->field_type) {

            printf("| %c ", struct_field_pointer->value_char);
        } else if (FIELD_TYPE_STRING == struct_field_pointer->field_type) {

            printf("| %s ", struct_field_pointer->value_string);
        }
    }
    printf(NONE);
}

/**
 * 打印一条记录
 * @param first_field
 */
void table_painter_print_table_record_info(Struct_Field *first_field) {

    printf(BLUE "| %d ", first_field->record_index);
    while (NULL != first_field) {

        table_painter_print_table_field_info(first_field);
        first_field = first_field->next;
    }
    printf(BLUE "\n---------------------------------------------------\n");
}
