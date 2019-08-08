#ifndef SERVER_SHERK_STORAGE_VENDOR_STORAGE_SERIALIZATION_MODULE_LOYAL_SERIALIZER_H
#define SERVER_SHERK_STORAGE_VENDOR_STORAGE_SERIALIZATION_MODULE_LOYAL_SERIALIZER_H

#include <SherkSupport/src/include/serialize/tobe_serialized_structs.h>

extern void loyal_serializer_serialize_field(Struct_Table *struct_table_pointer, char *field_file);

extern Struct_Table *loyal_serializer_unserialize_field(char *field_file);

extern void loyal_serializer_serialize_table(Struct_Table *struct_table_pointer, char *file);

extern Struct_Table *loyal_serializer_unserialize_table(char *table);

extern void loyal_serializer_serialize_frm(Struct_Table *struct_table_pointer, char *file);

extern Struct_Table *loyal_serializer_unserialize_frm(char *frm_file);


#endif
