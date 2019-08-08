#ifndef SERVER_SHERK_SUPPORT_MODULE_SKELETON_H
#define SERVER_SHERK_SUPPORT_MODULE_SKELETON_H

// 字段类型
extern const int FIELD_TYPE_ERROR;
extern const int FIELD_TYPE_DEFINITION;
extern const int FIELD_TYPE_INT;
extern const int FIELD_TYPE_FLOAT;
extern const int FIELD_TYPE_CHAR;
extern const int FIELD_TYPE_STRING;


// 数据库支持的引擎类型
extern const int DATABASE_SUPPORT_ENGINE_TYPE_INNODB;
extern const int DATABASE_SUPPORT_ENGINE_TYPE_MYISM;

// 数据库支持的字符集
extern const int DATABASE_SUPPORT_CHARSET_TYPE_UTF8;

// 系统数据库名字 : infoschema
// 系统数据库中包含的表有 :
// 1. 用户表 : users
// 2. 表管理表 : tables_manage
// 3. 库管理表 : databases_manage
extern const int WHICH_SYSTEM_TABLE_USERS;
extern const int WHICH_SYSTEM_TABLE_TABLES_MANAGE;
extern const int WHICH_SYSTEM_TABLE_DATABASES_MANAGE;

// 最大个数和最大长度
extern const int TABLE_STRUCT_JSON_MAX_LEN;
extern const int RECORD_MAX_COUNT;
extern const int FIELD_MAX_COUNT;
extern const int FIELD_JSON_MAX_LEN;
extern const int RECORD_JSON_MAX_LEN;

// 支持的运算符
extern const int OPERATOR_LESS; // <
extern const int OPERATOR_EQ; // =
extern const int OPERATOR_MORE; // >
extern const int OPERATOR_LESS_EQ; // <=
extern const int OPERATOR_MORE_EQ; // >=

// 支持的权限
extern const int PRIVILEGE_GRANT_SHOW;
extern const int PRIVILEGE_GRANT_CREATE;
extern const int PRIVILEGE_GRANT_DROP;
extern const int PRIVILEGE_GRANT_INSERT;
extern const int PRIVILEGE_GRANT_DELETE;
extern const int PRIVILEGE_GRANT_UPDATE;
extern const int PRIVILEGE_GRANT_SELECT;

#endif
