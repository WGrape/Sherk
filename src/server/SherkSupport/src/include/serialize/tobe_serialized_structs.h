#ifndef SERVER_SHERK_SUPPORT_INCLUDE_SERIALIZE_TOBE_SERIALIZED_STRUCTS_H
#define SERVER_SHERK_SUPPORT_INCLUDE_SERIALIZE_TOBE_SERIALIZED_STRUCTS_H

typedef struct Struct_Field Struct_Field;

// 数据库结构体
typedef struct Struct_Database {

    int id; // 数据库id
    char *name; // 数据库名

} Struct_Database;

// 数据表结构体
typedef struct Struct_Table {

    int id; // 数据表id
    char *name; // 数据表名
    char *database_name; // 数据库名

    int field_counts; // 字段的总个数
    int record_counts; // 记录的总个数

    char *physical_location; // 数据表的物理位置

    int auto_increment; // 自增
    int engine; // 选择的引擎
    int charset; // 选择的字符集

    Struct_Field *first_field; // 指向第一个字段
    Struct_Field *last_field; // 指向最后一个字段

    Struct_Field *first_record; // 指向第一个记录
    Struct_Field *last_record; // 指向最后一个记录

} Struct_Table;

// 字段结构体
struct Struct_Field {

    int id; // 字段id
    int field_type; // 字段类型, 只支持 int, float, char, string,
    char *field_name; // 字段名
    // char *value; // 字段的值, 均用字符串接收, 所以需要强转化

    int value_int;
    float value_float;
    char value_char;
    char *value_string;

    int field_index; // 字段的下标
    int record_index; // 记录的下标

    int is_definition; // 表示这个字段是记录还是定义
    int is_primary_key; // 表示这个字段是否是主键


    Struct_Field *current; // 当前的地址
    Struct_Field *next; // 指向下一个字段
    Struct_Field *next_record; // 指向下一个记录, 如果此字段是主键

    Struct_Field *last; // 上一个字段
    Struct_Field *last_record; // 上一条记录
};

typedef struct Struct_Record {

    Struct_Field *struct_field_pointer;
}Struct_Record;

// 系统数据库结构体
typedef struct Struct_Database_information_schema {


} Information_schema;

#endif
