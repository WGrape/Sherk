#ifndef SERVER_SHERK_SERVICE_TEST_MODULE_TEST_SQL_H
#define SERVER_SHERK_SERVICE_TEST_MODULE_TEST_SQL_H

extern void
test_sql_print_field_value_list(int count, char **field_name_list, int *field_type_list, int *field_value_int,
                                float *field_value_float,
                                char *field_value_char, char **field_value_string);

extern void test_sql_print_field_name_list(char **field_name_list, int count);

extern void test_sql_print_field_type_list(int *field_type_list, int count);

#endif
