#ifndef SERVER_SHERK_SQL_MODULE_ANALYST_H
#define SERVER_SHERK_SQL_MODULE_ANALYST_H

extern int analyst_analysis_sql_category(char *sql);

extern char *analyst_analysis_command_login_get_name(char *command);

extern char *analyst_analysis_command_login_get_password(char *command);

extern char *analyst_analysis_sql_use_database_get_database_name(char *command);

extern char *analyst_analysis_sql_create_database_get_database_name(char *command);

extern char *analyst_analysis_sql_drop_table_get_table_name(char *command);

extern char *analyst_analysis_sql_delete_from_table_get_table_name(char *command);

extern char *analyst_analysis_sql_create_table_get_table_name(char *command);

extern char *analyst_analysis_sql_desc_table_get_table_name(char *command);

extern char *analyst_analysis_sql_desc_table_field_get_table_name(char *command);

extern char *analyst_analysis_sql_select_table_part_get_table_name(char *command);

extern char *analyst_analysis_sql_update_table_get_table_name(char *command);

extern char *analyst_analysis_sql_insert_table_get_table_name(char *command);

extern char *analyst_analysis_sql_insert_table_get_record(char *command);

extern char *analyst_analysis_sql_insert_table_get_record_update(char *command);

extern char *analyst_analysis_sql_select_table_get_table_name(char *command);

extern int analyst_analysis_field_type_by_field_type_string(char *field_type);

extern int analyst_analysis_field_type_by_field_value_string(const char *field_value);

extern char **analyst_analysis_sql_create_table_get_field_name_list(char *command);

extern int *analyst_analysis_sql_create_table_get_field_type_list(char *command);

extern int analyst_analysis_sql_is_create_sys_table(char *table_name);

extern char **analyst_analysis_sql_create_sys_table_get_field_name_list(char *command, char *table_name);

extern int *analyst_analysis_sql_create_sys_table_get_field_type_list(char *command, char *table_name);


#endif
