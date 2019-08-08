#ifndef SERVER_SHERK_SQL_MODULE_EXTRACTOR_H
#define SERVER_SHERK_SQL_MODULE_EXTRACTOR_H

extern void
extractor_extract_update_sql(char *sql, int *count, char **field_name_list, int *field_type_list, int *field_value_int,
                             float *field_value_float,
                             char *field_value_char, char **field_value_string,
                             char **condition_name_list, char **condition_operator_list, char **condition_value_list);

extern void
extractor_extract_insert_sql(char *sql, int *count, char **field_name_list, int *field_type_list, int *field_value_int,
                             float *field_value_float,
                             char *field_value_char, char **field_value_string);

extern void extractor_extract_create_sql(char *sql, char **field_name_list, int *field_type_list, int *field_count);

#endif

