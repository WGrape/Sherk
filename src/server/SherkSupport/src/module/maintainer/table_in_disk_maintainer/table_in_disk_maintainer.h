#ifndef SERVER_SHERK_SUPPORT_MODULE_MAINTAINER_TABLE_IN_DISK_MAINTAINER_H
#define SERVER_SHERK_SUPPORT_MODULE_MAINTAINER_TABLE_IN_DISK_MAINTAINER_H

extern void table_in_disk_maintainer_desc_table(char *table_frm_file);

extern void table_in_disk_maintainer_desc_table_field(char *table_field_file);

extern int table_in_disk_maintainer_table_is_exist(char *database_name, char *table_name);

extern Struct_Table *table_in_disk_maintainer_select_table(char *database_name, char *table_name);

extern void table_in_disk_maintainer_select_table_where_by_id(Struct_Table *struct_table_pointer, int operator, int id);

extern void table_in_disk_maintainer_insert_table(char *table_file, char *record);

extern void
table_in_disk_maintainer_create_table(char *database_name, char *table_name, Struct_Table *struct_table_pointer);

extern FILE *table_in_disk_maintainer_show_tables(char *database_name, int delete);

extern void table_in_disk_maintainer_drop_table(char *database_name, char *table_name, int infoschema_callback);


#endif
