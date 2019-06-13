cmake_minimum_required(VERSION 3.1.0)
project(sherk_language_connector C)

set(CMAKE_C_STANDARD 99)
SET(CMAKE_C_FLAGS "-lconfig")

# 使用此配置头文件，头文件不用再写成 "../../../" 这样丑陋的路径了
include_directories(../language_connector)

set(PHP_DIR ./php)
add_executable(sherk_language_connector ./language_connector.c

        ${PHP_DIR}/php_connector.h
        ${PHP_DIR}/php_connector.c

        )

