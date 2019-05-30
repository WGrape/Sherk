#include <stdio.h>
#include <SherkSupport/src/module/skeleton/skeleton.h>
#include <SherkService/mechanism/module/grocery/grocery.h>

void test_sql_print_field_value_list(int count, char **field_name_list, int *field_type_list, int *field_value_int,
                                     float *field_value_float,
                                     char *field_value_char, char **field_value_string) {

    int i = 0;

    printf("--------------------------------\n");
    printf("| field_value_list \n");
    printf("--------------------------------\n");
    for (i = 0; i <= count - 1; ++i) {

        if (FIELD_TYPE_STRING == field_type_list[i]) {

            printf("| %s\n", field_value_string[i]);
        } else if (FIELD_TYPE_FLOAT == field_type_list[i]) {

            printf("| %f\n", field_value_float[i]);
        } else if (FIELD_TYPE_CHAR == field_type_list[i]) {

            printf("| %c\n", field_value_char[i]);
        }else{

            printf("| %d\n", field_value_int[i]);
        }

        printf("--------------------------------\n");
    }
}

void test_sql_print_field_name_list(char **field_name_list, int count) {

    int i = 0;

    printf("--------------------------------\n");
    printf("| field_name_list \n");
    printf("--------------------------------\n");
    for (i = 0; i <= count - 1; ++i) {

        printf("| %s\n", field_name_list[i]);
        printf("--------------------------------\n");
    }
}

void test_sql_print_field_type_list(int *field_type_list, int count) {

    int i = 0;

    printf("--------------------------------\n");
    printf("| field_type_list \n");
    printf("--------------------------------\n");
    for (i = 0; i <= count - 1; ++i) {

        printf("| %d\n", field_type_list[i]);
        printf("--------------------------------\n");
    }
}
