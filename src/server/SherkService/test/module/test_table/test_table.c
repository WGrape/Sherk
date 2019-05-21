#include <stdio.h>
#include <SherkSupport/src/include/serialize/tobe_serialized_structs.h>
#include <SherkSupport/src/module/table_maintainer/table_maintainer.h>
#include <SherkSupport/src/module/table_painter/table_painter.h>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
#include <SherkSupport/src/include/const/core.h>
#include <SherkService/mechanism/module/grocery/grocery.h>


void table_traverser_sow_seeds_to_table(Struct_Table *struct_table_pointer) {

    int i = 0, j = 0;

    // 生成随机的字段数和记录数
    srand((unsigned) time(NULL));
    int record_counts = (rand() % (10 - 1)) + 1; // 生成 1 - 10 随机数
    int field_counts = (rand() % (5 - 2)) + 2; // 生成 2 - 5 随机数
    int random_value;

    record_counts = 5;
    field_counts = 5;

    // 记录到struct_table_pointer中
    struct_table_pointer->field_counts = field_counts;
    struct_table_pointer->record_counts = record_counts;

    // 先生成表头
    char *field_name;
    struct_table_pointer->first_field = NULL;
    Struct_Field *last = NULL;
    Struct_Field *current = NULL;
    Struct_Field *last_record = NULL;
    Struct_Field *current_record = NULL;
    for (i = 0; i <= record_counts; ++i) {
        for (j = 0; j <= field_counts - 1; ++j) {

            // 需要给字段赋的值
            random_value = rand();
            field_name = (char *) malloc(sizeof(char) * 100); // 很坑又很重要且正常的问题 : 如果是 char field_name[100] 则会覆盖
            memset(field_name, '\0', 100);
            sprintf(field_name, "column_%d", j);

            // 创建字段
            if (0 == i) {

                // 创建的是定义字段
                current = table_traverser_create_a_field_int(FIELD_TYPE_INT, field_name,
                                                             random_value, j,
                                                             1,
                                                             0 == j);
            } else {

                // 创建的是值字段
                current = table_traverser_create_a_field_int(FIELD_TYPE_INT, field_name,
                                                             random_value, j,
                                                             0,
                                                             0 == j);
            }
            current_record = current;
            current->record_index = i;

            // 第一个字段 和 最后一个字段
            if (0 == i && 0 == j) {

                struct_table_pointer->first_field = current;
            }
            if (0 == i && field_counts - 1 == j) {

                struct_table_pointer->last_field = current;
            }

            // 第一条记录 和 最后一条记录
            if (1 == i && 0 == j) {

                struct_table_pointer->first_record = current_record;
            }
            if (record_counts == i && 0 == j) {

                struct_table_pointer->last_record = current_record;
            }

            // 行串联起来
            if (0 < j && NULL != current) {

                // printf("\nlast: %p , current: %p ", last, current);
                last->next = current;
                current->last = last;
            }
            last = current;

            // 列串联起来
            if (0 == i && 0 == j) {
                last_record = current_record;
            }
            if (0 < i && 0 == j && NULL != current_record) {

                // printf("\nlast_record: %p , current_record: %p", last_record, current_record);
                last_record->next_record = current_record;
                current_record->last_record = last_record;
                last_record = current_record;
            }

            // 因为我打印的是当前的字段, 所以 next 才一直都是NULL, 不是我的程序有问题 !
            // table_traverser_test_print_table_record_info(current);
        }

        // table_traverser_test_print_table_record_info(struct_table_pointer->first_field);
    }

    // table_traverser_print_table_record_info(struct_table_pointer->first_field);
}



// 模拟出一张demo表
Struct_Table *
table_traverser_simulate_a_table_demo(char *database_name, char *name, int auto_increment, int engine, int charset) {

    Struct_Table *struct_table_pointer = table_traverser_create_a_table(database_name, name, auto_increment, engine,
                                                                        charset);

    table_traverser_sow_seeds_to_table(struct_table_pointer);

    // loyal_serializer_serialize_table(struct_table_pointer);

    return struct_table_pointer;
}



/**
 * TEST: 打印表的结构信息
 * @param struct_table_pointer
 */
void table_traverser_test_print_table_struct_info(Struct_Table *struct_table_pointer) {

    printf("\n数据表信息测试结果如下 :");
    printf("\n----------------------------------------\n");


    printf("| id                | %d\n", struct_table_pointer->id);

    printf("| name              | %s\n", struct_table_pointer->name);
    printf("| engine            | %d\n", struct_table_pointer->engine);
    printf("| charset           | %d\n", struct_table_pointer->charset);

    printf("| last_field        | %p\n", struct_table_pointer->last_field);
    printf("| first_field       | %p\n", struct_table_pointer->first_field);
    printf("| last_record       | %p\n", struct_table_pointer->last_record);
    printf("| first_record      | %p\n", struct_table_pointer->first_record);

    printf("| field_counts      | %d\n", struct_table_pointer->field_counts);
    printf("| record_counts     | %d\n", struct_table_pointer->record_counts);

    printf("| database_name     | %s\n", struct_table_pointer->database_name);
    printf("| auto_increment    | %d\n", struct_table_pointer->auto_increment);
    printf("| physical_location | %s\n", struct_table_pointer->physical_location);

    printf("----------------------------------------\n");

}


/**
 * TEST: 打印表字段的信息
 * @param struct_field_pointer
 */
void table_traverser_test_print_table_field_info(Struct_Field *struct_field_pointer) {

    printf("\n数据表字段测试数据如下 :");
    printf("\n----------------------------------------\n");

    printf("| last            | %p\n", struct_field_pointer->last);
    printf("| current         | %p\n", struct_field_pointer->current);
    printf("| next            | %p\n", struct_field_pointer->next);
    printf("| next_record     | %p\n", struct_field_pointer->next_record);

    printf("| id              | %d\n", struct_field_pointer->id);
    printf("| record_index    | %d\n", struct_field_pointer->record_index);
    printf("| field_index     | %d\n", struct_field_pointer->field_index);

    printf("| is_primary_key  | %d\n", struct_field_pointer->is_primary_key);
    printf("| is_definition   | %d\n", struct_field_pointer->is_definition);

    printf("| value_int       | %d\n", struct_field_pointer->value_int);
    printf("| value_float     | %f\n", struct_field_pointer->value_float);
    printf("| value_char      | %c\n", struct_field_pointer->value_char);
    printf("| value_string    | %s\n", struct_field_pointer->value_string);
    printf("| field_name      | %s\n", struct_field_pointer->field_name);
    printf("| field_type      | %d\n", struct_field_pointer->field_type);

    printf("----------------------------------------\n");

}


/**
 * TEST: 打印表信息, 包括表头和数据的信息
 * @param struct_table
 */
void table_traverser_print_table_info(Struct_Table *struct_table_pointer) {

    int i = 0, record_counts = struct_table_pointer->record_counts;
    grocery_console_print_with_blue_color("\n--------------正在打印此整张表------------->\n");

    Struct_Field *field_pointer = struct_table_pointer->first_field;
    for (; i <= record_counts; ++i) {

        // printf("field_pointer = %p, ", field_pointer);
        table_painter_print_table_record_info(field_pointer);
        field_pointer = field_pointer->next_record;
    }

    grocery_console_print_with_blue_color("\n<-------------正在打印此整张表--------------\n");
}

/**
 * TEST: 打印表记录信息
 * @param first_field
 */
void table_traverser_test_print_table_record_info(Struct_Field *first_field) {

    grocery_console_print_with_blue_color("\n-------------正在打印一条记录------------->\n");
    while (NULL != first_field) {

        table_traverser_test_print_table_field_info(first_field);
        first_field = first_field->next;
    }
    grocery_console_print_with_blue_color("\n<-------------结束打印一条记录-------------\n");
}



/**
 * TEST: 打印表列的信息
 * @param column_first_field
 */
void table_traverser_test_print_table_column_info(Struct_Field *column_first_field) {

    grocery_console_print_with_blue_color("\n-------------正在打印一列记录------------->\n");
    while (NULL != column_first_field) {

        table_traverser_test_print_table_field_info(column_first_field);
        column_first_field = column_first_field->next_record;
    }
    grocery_console_print_with_blue_color("\n<-------------结束打印一列记录-------------\n");
}


