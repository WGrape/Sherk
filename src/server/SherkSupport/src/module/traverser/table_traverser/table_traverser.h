#ifndef SERVER_SHERK_SUPPORT_MODULE_TRAVERSER_TABLE_TRAVERSER_H
#define SERVER_SHERK_SUPPORT_MODULE_TRAVERSER_TABLE_TRAVERSER_H

#include <SherkSupport/src/include/serialize/tobe_serialized_structs.h>


extern char *table_traverser_get_table_struct_json(Struct_Table *struct_table_pointer);

extern Struct_Field table_traverser_get_a_field(Struct_Field *struct_field_pointer);

extern char *table_traverser_get_a_field_json(Struct_Field *struct_field_pointer);

extern char *table_traverser_get_a_field_json(Struct_Field *struct_field_pointer);

extern char *table_traverser_get_a_record_json(Struct_Field *struct_field_pointer, int count);

extern void table_traverser_reset_index_in_order(Struct_Table *struct_table_pointer);


#endif
