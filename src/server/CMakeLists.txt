cmake_minimum_required(VERSION 3.1.0)
project(Sherk C)

set(CMAKE_C_STANDARD 99)

# 使用此配置头文件，头文件不用再写成 "../../../" 这样丑陋的路径了
include_directories(../server)

# 由于用到了线程, 所以需要此配置
set(THREADS_PREFER_PTHREAD_FLAG ON)
add_library(Threads::Threads INTERFACE IMPORTED)

# sherkd表示编译后的可执行文件名为 sherkd
add_executable(sherkd ./sherkd.c)


# 由于用到了线程, 所以需要此配置
target_link_libraries(sherkd pthread)

