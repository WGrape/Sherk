#include <stdio.h>
#include <stdlib.h>
#include <SherkLaunch/src/sherkLaunch.h>
#include <SherkLink/src/vendor/process_pool/master_worker.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <string.h>
#include <SherkSQL/src/module/analyst/analyst.h>
#include <SherkService/test/module/test_sql/test_sql.h>
#include <SherkSQL/src/module/extractor/extractor.h>
#include <SherkSQL/src/module/builder/builder.h>


int main() {

    // sherkLaunch_start();
    char **field_name_list = (char **) malloc(sizeof(char **) * 100);
    int *field_type_list = (int *) malloc(sizeof(int *) * 100);
    int *field_value_int = (int *) malloc(sizeof(int *) * 100);
    float *field_value_float = (float *) malloc(sizeof(float *) * 100);
    char *field_value_char = (char *) malloc(sizeof(char *) * 100);
    char **field_value_string = (char **) malloc(sizeof(char **) * 100);
    int field_count = 0;

    char **condition_name_list = (char **) malloc(sizeof(char **) * 100);
    char **condition_operator_list = (char **) malloc(sizeof(char **) * 100);
    char **condition_value_list = (char **) malloc(sizeof(char **) * 100);


    char *sql = "update test set      name = \"lvsi\", age = 54, flag = 762     where       id = 76 and name = \"jay\"    ";
    extractor_extract_update_sql(sql, &field_count, field_name_list, field_type_list, field_value_int,
                                 field_value_float, field_value_char, field_value_string, condition_name_list,
                                 condition_operator_list, condition_value_list);

    return 0;
}