cmake_minimum_required(VERSION 3.1.0)
project(sherk C)

set(CMAKE_C_STANDARD 99)
SET(CMAKE_C_FLAGS "-lconfig")

# 使用此配置头文件，头文件不用再写成 "../../../" 这样丑陋的路径了
include_directories(../client)

# windows 的 Cmake 编译出错，添加此即可
# link_libraries(ws2_32)

# sherkd表示编译后的可执行文件名为 sherk
set(INCLUDE_DIR ./include)
set(MODULE_DIR ./module)
add_executable(sherk ./sherk.c

        ${INCLUDE_DIR}/define/const.h
        ${INCLUDE_DIR}/define/message.h
        ${INCLUDE_DIR}/define/rescode.h

        ${INCLUDE_DIR}/object/SocketResponseData.h
        ${INCLUDE_DIR}/object/User.h

        ${INCLUDE_DIR}/helper/color.h
        ${INCLUDE_DIR}/helper/string.h

        ${MODULE_DIR}/administrator/administrator.c
        ${MODULE_DIR}/administrator/administrator.h

        ${MODULE_DIR}/certificate/certificate.c
        ${MODULE_DIR}/certificate/certificate.h

        ${MODULE_DIR}/command/command.c
        ${MODULE_DIR}/command/command.h

        ${MODULE_DIR}/encrypter/encrypter.c
        ${MODULE_DIR}/encrypter/encrypter.h

        ${MODULE_DIR}/express/express.c
        ${MODULE_DIR}/express/express.h

        ${MODULE_DIR}/grocery/grocery.c
        ${MODULE_DIR}/grocery/grocery.h

        ${MODULE_DIR}/network/network.c
        ${MODULE_DIR}/network/network.h

        ${MODULE_DIR}/test/test.c
        ${MODULE_DIR}/test/test.h

        ${MODULE_DIR}/ui/ui.c
        ${MODULE_DIR}/ui/ui.h

        )

