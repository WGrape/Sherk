#ifndef SERVER_SHERK_ENGINE_MODULE_SERVLET_TABLE_SERVLET_H
#define SERVER_SHERK_ENGINE_MODULE_SERVLET_TABLE_SERVLET_H

extern int table_servlet_show_tables();

extern int table_servlet_desc_table(char *table_name);

extern int table_servlet_desc_table_field(char *table_name);

extern int table_servlet_select_table(char *table_name);

extern int table_servlet_select_table_part(char *table_name);

extern int table_servlet_update_table(char *table_name, int field_count, char **field_name_list, int *field_type_list,
                                      int *field_value_int,
                                      float *field_value_float, char *field_value_char, char **field_value_string,
                                      char **condition_name_list, char **condition_operator_list,
                                      char **condition_value_list);

extern int table_servlet_insert_table(char *table_name, char *record);

extern void table_servlet_drop_table(char *table_name);

extern void table_servlet_delete_table(char *table_name);

extern int table_servlet_create_table(char *table_name, char **field_name_list, int *field_type_list, int field_count);

#endif
