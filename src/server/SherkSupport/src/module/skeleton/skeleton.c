#include <stdio.h>


// 字段类型
const int FIELD_TYPE_ERROR = -999;
const int FIELD_TYPE_DEFINITION = -1; // 字段是定义
const int FIELD_TYPE_INT = 1; // 字段是int整型
const int FIELD_TYPE_FLOAT = 2; // 字段是浮点小数类型
const int FIELD_TYPE_CHAR = 3; // 字段是字符类型
const int FIELD_TYPE_STRING = 4; // 字段是字符串类型

// 数据库支持的引擎类型
const int DATABASE_SUPPORT_ENGINE_TYPE_INNODB = 1; // 数据库支持的引擎为 innodb
const int DATABASE_SUPPORT_ENGINE_TYPE_MYISM = 2; // 数据库支持的引擎为 Myism

// 数据库支持的字符集
const int DATABASE_SUPPORT_CHARSET_TYPE_UTF8 = 1; // 数据库支持的字符集为 utf8


// 系统数据库名字 : infoschema
// 系统数据库中包含的表有 :
// 1. 用户表 : users
// 2. 表管理表 : tables_manage
// 3. 库管理表 : databases_manage
const int WHICH_SYSTEM_TABLE_USERS = 1;
const int WHICH_SYSTEM_TABLE_TABLES_MANAGE = 2;
const int WHICH_SYSTEM_TABLE_DATABASES_MANAGE = 3;


// 最大个数和最大长度
const int TABLE_STRUCT_JSON_MAX_LEN = 500;
const int RECORD_MAX_COUNT = 100;
const int FIELD_MAX_COUNT = 10;
const int FIELD_JSON_MAX_LEN = 5000;
const int RECORD_JSON_MAX_LEN = 50000;


// 支持的运算符
const int OPERATOR_LESS = 1; // <
const int OPERATOR_EQ = 2; // =
const int OPERATOR_MORE = 3; // >
const int OPERATOR_LESS_EQ = 4; // <=
const int OPERATOR_MORE_EQ = 5; // >=


// 权限
const int PRIVILEGE_GRANT_SHOW = 1;
const int PRIVILEGE_GRANT_CREATE = 2;
const int PRIVILEGE_GRANT_DROP = 3;
const int PRIVILEGE_GRANT_INSERT = 4;
const int PRIVILEGE_GRANT_DELETE = 5;
const int PRIVILEGE_GRANT_UPDATE = 6;
const int PRIVILEGE_GRANT_SELECT = 7;


