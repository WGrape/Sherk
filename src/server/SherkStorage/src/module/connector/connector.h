#ifndef SERVER_SHERK_STORAGE_MODULE_CONNECTOR_H
#define SERVER_SHERK_STORAGE_MODULE_CONNECTOR_H

extern void connector_write_field(char *file, Struct_Table *struct_table_pointer);

extern Struct_Table *connector_read_field(char *file);

extern void connector_write_table(char *file, Struct_Table *struct_table_pointer);

extern Struct_Table *connector_read_table(char *file);

extern void connector_write_frm(char *file, Struct_Table *struct_table_pointer);

extern Struct_Table *connector_read_frm(char *file);

#endif


