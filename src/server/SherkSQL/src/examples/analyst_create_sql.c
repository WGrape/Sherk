#include <stdio.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <SherkSQL/src/module/analyst/analyst.h>

void test() {

    char *sql = "create table( id int , name string )";

    // 字段数
    int field_count = grocery_char_in_string_appear_times(sql, ',') + 1;

    // 字段名列表, 字段类型列表
    char **field_name_list = (char **) malloc(sizeof(char **) * 100);
    int *field_type_list = (int *) malloc(sizeof(int *) * 100);

    // 开始循环获取
    int i, j;
    char *field_definition; // 每一个字段的定义
    char *field_type; // 字段类型
    if (1 == field_count) {

        field_definition = grocery_string_crimp(sql, '(', 1, ')', 1);
        field_name_list[0] =
                grocery_string_split_by_whitespace_into_two_part(field_definition)[0];
        field_type = grocery_string_split_by_whitespace_into_two_part(field_definition)[1];
        field_type_list[0] =
                analyst_analysis_field_type_by_field_type_string(field_type);

    } else {

        for (
                i = 0;
                i <= field_count - 1; ++i) {

            if (0 == i) { // 获取第1个字段定义的时候

                field_definition = grocery_string_crimp(sql, '(', 1, ',', 1);
            } else if (field_count - 1 == i) { // 获取最后1个字段定义的时候

                field_definition = grocery_string_crimp(sql, ',', i, ')', 1);
            } else {

                field_definition = grocery_string_crimp(sql, ',', i, ',', i + 1);
            }

            printf("field_definition:%s\n", field_definition);
        }
    }
}