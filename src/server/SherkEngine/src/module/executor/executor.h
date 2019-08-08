#ifndef SERVER_SHERK_ENGINE_MODULE_EXECUTOR_H
#define SERVER_SHERK_ENGINE_MODULE_EXECUTOR_H


extern char *executor_handle_command_login(char *name, char *password);

extern void executor_handle_sql_show_databases();

extern int executor_handle_sql_show_tables();

extern void executor_handle_sql_use_database(char *database_name);

extern void executor_handle_sql_create_database(char *database_name);

extern void executor_handle_sql_drop_database(char *database_name);

extern int executor_handle_sql_desc_table(char *table_name);

extern int executor_handle_sql_desc_table_field(char *table_name);

extern int executor_handle_sql_select_table(char *table_name);

extern int executor_handle_sql_select_table_part(char *table_name);

extern int executor_handle_sql_insert_table(char *table_name, char *record);

extern int
executor_handle_sql_update_table(char *table_name, int field_count, char **field_name_list, int *field_type_list,
                                 int *field_value_int,
                                 float *field_value_float, char *field_value_char, char **field_value_string,
                                 char **condition_name_list, char **condition_operator_list,
                                 char **condition_value_list);

extern void executor_handle_sql_drop_table(char *table_name);

extern void executor_handle_sql_delete_table(char *table_name);

extern int
executor_handle_sql_create_table(char *table_name, char **field_name_list, int *field_type_list, int field_count);


#endif
