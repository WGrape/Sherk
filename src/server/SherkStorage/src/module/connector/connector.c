#include <stdio.h>
#include <SherkStorage/src/module/mounter/mounter.h>
#include <SherkStorage/src/vendor/storage_serialization/module/loyal_serializer/loyal_serializer.h>

/**
 * 连接器: 把数据表的字段信息写到磁盘上
 * @param file
 * @param struct_table_pointer
 */
void connector_write_field(char *file, Struct_Table *struct_table_pointer) {

    // 先挂载存储
    int storage_plan = mounter_mount_storage();

    if (STORAGE_PLAN_SERIALIZATION == storage_plan) {

        // 使用序列化把存储到此文件
        loyal_serializer_serialize_field(struct_table_pointer, file);
    }
}

/**
 * 连接器: 把磁盘上数据表的字段文件读到内存中
 * @param file
 * @return
 */
Struct_Table *connector_read_field(char *file) {

    // 使用序列化把存储到此文件
    return loyal_serializer_unserialize_field(file);
}

/**
 * 连接器: 把数据表的数据信息写到到磁盘上
 * @param file
 * @param struct_table_pointer
 */
void connector_write_table(char *file, Struct_Table *struct_table_pointer) {

    // 先挂载存储
    int storage_plan = mounter_mount_storage();

    if (STORAGE_PLAN_SERIALIZATION == storage_plan) {

        // 使用序列化把存储到此文件
        loyal_serializer_serialize_table(struct_table_pointer, file);
    }
}

/**
 * 连接器: 把磁盘上数据表的数据文件读到内存中
 * @param file
 * @return
 */
Struct_Table *connector_read_table(char *file) {

    // 把文件逆序列化到内存中
    return loyal_serializer_unserialize_table(file);
}

/**
 * 连接器: 把数据表的结构信息写到磁盘上
 * @param file
 * @param struct_table_pointer
 */
void connector_write_frm(char *file, Struct_Table *struct_table_pointer) {

    // 先挂载存储
    int storage_plan = mounter_mount_storage();

    if (STORAGE_PLAN_SERIALIZATION == storage_plan) {

        // 使用序列化把存储到此文件
        loyal_serializer_serialize_frm(struct_table_pointer, file);
    }
}

/**
 * 连接器: 把磁盘上数据表的结构文件读到内存中
 * @param table_frm_file
 * @return
 */
Struct_Table *connector_read_frm(char *table_frm_file) {

    // 使用序列化把存储到此文件
    return loyal_serializer_unserialize_frm(table_frm_file);
}


