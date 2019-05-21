cmake_minimum_required(VERSION 3.1.0)
project(sherkd C)

SET(CMAKE_C_STANDARD 99)
SET(CMAKE_C_FLAGS "-lconfig")
SET(CMAKE_C_FLAGS_DEBUG "-lmsgpackc")
# SET(CMAKE_C_FLAGS "-lmsgpackc") # 这样写就会报错 : https://stackoverflow.com/questions/10085945/set-cflags-and-cxxflags-options-using-cmake
# 参考: https://stackoverflow.com/questions/10085945/set-cflags-and-cxxflags-options-using-cmake

# 创建新的源文件时, 要记得及时 Reload CMake Project

# 使用此配置头文件，头文件不用再写成 "../../../" 这样丑陋的路径了
include_directories(../server)

# file(GLOB_RECURSE c_source_list "../server/*.c")
# file(GLOB_RECURSE h_source_list "../server/*.h")
# add_executable(sherkd ${c_source_list} ${h_source_list})


file(GLOB_RECURSE source_list_sherkEngine_h "./SherkEngine/*.h")
file(GLOB_RECURSE source_list_sherkLaunch_h "./SherkLaunch/*.h")
file(GLOB_RECURSE source_list_sherkLink_h "./SherkLink/*.h")
file(GLOB_RECURSE source_list_sherkService_h "SherkService/*.h")
file(GLOB_RECURSE source_list_sherkSQL_h "./SherkSQL/*.h")
file(GLOB_RECURSE source_list_sherkStorage_h "./SherkStorage/*.h")
file(GLOB_RECURSE source_list_sherkSupport_h "./SherkSupport/*.h")

file(GLOB_RECURSE source_list_sherkEngine_c "./SherkEngine/*.c")
file(GLOB_RECURSE source_list_sherkLaunch_c "./SherkLaunch/*.c")
file(GLOB_RECURSE source_list_sherkLink_c "./SherkLink/*.c")
file(GLOB_RECURSE source_list_sherkService_c "SherkService/*.c")
file(GLOB_RECURSE source_list_sherkSQL_c "./SherkSQL/*.c")
file(GLOB_RECURSE source_list_sherkStorage_c "./SherkStorage/*.c")
file(GLOB_RECURSE source_list_sherkSupport_c "./SherkSupport/*.c")

add_executable(sherkd ./sherkd.c

        ${source_list_sherkEngine_h}
        ${source_list_sherkLaunch_h}
        ${source_list_sherkLink_h}
        ${source_list_sherkSQL_h}
        ${source_list_sherkStorage_h}
        ${source_list_sherkSupport_h}
        ${source_list_sherkService_h}


        ${source_list_sherkEngine_c}
        ${source_list_sherkLaunch_c}
        ${source_list_sherkLink_c}
        ${source_list_sherkSQL_c}
        ${source_list_sherkStorage_c}
        ${source_list_sherkSupport_c}
        ${source_list_sherkService_c}

        )

# 由于用到了线程, 所以需要此配置
target_link_libraries(sherkd pthread)
