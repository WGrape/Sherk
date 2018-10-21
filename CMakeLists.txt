cmake_minimum_required(VERSION 3.10)
project(Sherk C)

set(CMAKE_C_STANDARD 99)

add_executable(Sherk


        src/launcher/client.launcher.c
        src/launcher/server.launcher.c

        src/include/object/Client.class.h
        src/include/object/Panel.class.h
        src/include/object/Server.class.h

        Sherk.c )
