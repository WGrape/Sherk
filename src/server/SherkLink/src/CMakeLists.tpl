cmake_minimum_required(VERSION 3.1.0)
project(SherkLink C)

set(CMAKE_C_STANDARD 99)

# 使用此配置头文件，头文件不用再写成 "../../../" 这样丑陋的路径了
include_directories(../../../server)

file(GLOB_RECURSE c_source_list "../src/*.c")
file(GLOB_RECURSE h_source_list "../src/*.h")

add_executable(SherkLink ${c_source_list} ${h_source_list})

