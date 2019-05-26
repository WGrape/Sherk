#ifndef SERVER_SHERK_SERVICE_TEST_MODULE_TEST_TABLE_H
#define SERVER_SHERK_SERVICE_TEST_MODULE_TEST_TABLE_H

extern void test_table_print_tables(char *database_name);

extern void test_table_print_table_info(Struct_Table *struct_table_pointer);

extern void test_table_print_table_part_info(Struct_Table *struct_table_pointer, int from, int to);

extern void test_table_print_table_record_info(Struct_Field *first_field);

extern void test_table_print_table_struct_info(Struct_Table *struct_table_pointer);

extern void test_table_print_table_head_info(Struct_Table *struct_table_pointer);

#endif
