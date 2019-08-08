#ifndef SERVER_SHERK_SUPPORT_MODULE_MAINTAINER_TABLE_IN_MEMORY_MAINTAINER_H
#define SERVER_SHERK_SUPPORT_MODULE_MAINTAINER_TABLE_IN_MEMORY_MAINTAINER_H

#include <SherkSupport/src/include/serialize/tobe_serialized_structs.h>


extern void table_in_memory_maintainer_drop_table(char *database_name, char *table_name, int infoschema_callback);

extern Struct_Field *
table_in_memory_maintainer_create_a_field(Struct_Field *struct_field_pointer, int field_type, char *field_name,
                                          int field_index, int is_definition,
                                          int is_primary_key);

extern Struct_Table *
table_in_memory_maintainer_create_a_table(char *database_name, char *name, int auto_increment, int engine, int charset);

extern Struct_Table *
table_in_memory_maintainer_create_a_table_temp();

extern Struct_Field *
table_in_memory_maintainer_create_a_field_definition(int field_type,
                                                     char *field_name,
                                                     int field_index, int is_definition,
                                                     int is_primary_key);

extern Struct_Field *
table_in_memory_maintainer_create_a_field_int(int field_type,
                                              char *field_name,
                                              int value_int,
                                              int field_index, int is_definition,
                                              int is_primary_key);

extern Struct_Field *
table_in_memory_maintainer_create_a_field_float(int field_type,
                                                char *field_name,
                                                float value_float,
                                                int field_index, int is_definition,
                                                int is_primary_key);


extern Struct_Field *
table_in_memory_maintainer_create_a_field_char(int field_type,
                                               char *field_name,
                                               char value_char,
                                               int field_index, int is_definition,
                                               int is_primary_key);

extern Struct_Field *
table_in_memory_maintainer_create_a_field_string(int field_type,
                                                 char *field_name,
                                                 char *value_string,
                                                 int field_index, int is_definition,
                                                 int is_primary_key);

extern void table_in_memory_maintainer_insert_table_head(Struct_Table *struct_table_pointer,
                                                         Struct_Field *struct_table_head_pointer);

extern void
table_in_memory_maintainer_insert_a_record(Struct_Table *struct_table_pointer, Struct_Field *struct_field_pointer);

extern void
table_in_memory_maintainer_update_a_record(char *file, Struct_Table *struct_table_pointer, int field_count,
                                           char **field_name_list,
                                           int *field_type_list,
                                           int *field_value_int,
                                           float *field_value_float, char *field_value_char,
                                           char **field_value_string, char *column, int id);

extern void
table_in_memory_maintainer_append_a_field(Struct_Field *last_field_pointer, Struct_Field *struct_field_pointer);

extern Struct_Field *
table_in_memory_maintainer_create_table_head(Struct_Table *struct_table_pointer, char **field_name_list,
                                             const int *field_type_list, int field_count);

#endif
