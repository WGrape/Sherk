#ifndef SERVER_SHERK_SQL_MODULE_BUILDER_H
#define SERVER_SHERK_SQL_MODULE_BUILDER_H

extern char *
builder_generate_record_json(int field_count, char **field_name_list, int *field_type_list, int *field_value_int,
                             float *field_value_float, char *field_value_char, char **field_value_string);

#endif
