cmake_minimum_required(VERSION 3.1.0)
project(Sherk C)

set(CMAKE_C_STANDARD 99)

# 使用此配置头文件，头文件不用再写成 "../../../" 这样丑陋的路径了
include_directories(../server)

# 由于用到了线程, 所以需要此配置
set(THREADS_PREFER_PTHREAD_FLAG ON)
add_library(Threads::Threads INTERFACE IMPORTED)


# sherkd表示编译后的可执行文件名为 sherkd
set(INCLUDE_DIR ./include)
set(MODULE_DIR ./module)

#add_executable(sherkd ./sherkd.c
#
#        ${INCLUDE_DIR}/define/const.h
#        ${INCLUDE_DIR}/define/message.h
#        ${INCLUDE_DIR}/define/rescode.h
#
#        ${INCLUDE_DIR}/init/read_cnf.h
#
#        ${MODULE_DIR}/init/init.h
#        ${MODULE_DIR}/init/init.c
#
#
#        package/package.h package/algorithm/algorithm.h)

add_executable(sherkd ./sherkd.c module/architecture/engine/index/index.h)

# 由于用到了线程, 所以需要此配置
target_link_libraries(sherkd pthread)

