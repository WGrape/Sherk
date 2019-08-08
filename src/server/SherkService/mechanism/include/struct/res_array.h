#ifndef SERVER_SHERK_SERVICE_MECHANISM_INCLUDE_STRUCT_RES_ARRAY_H
#define SERVER_SHERK_SERVICE_MECHANISM_INCLUDE_STRUCT_RES_ARRAY_H

// 最强的响应数组数据结构, 这个结构可以让接收者获取到关于数组的详细信息
typedef struct RES_ARRAY{

    char ** array; // 默认是字符串数组
    int *array_int; // 整型数组


    int count;
    char *msg;

    // 额外数据, 一般不使用
    int extra_int;
    char extra_char;
    double extra_double;
    char *extra_string;
}RES_ARRAY ;

#endif