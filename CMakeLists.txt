cmake_minimum_required(VERSION 3.10)
project(Sherk C)

set(CMAKE_C_STANDARD 99)

add_executable(Sherk main.c main.c src/include/algorithm/Btree/B+tree.h src/client/client.c src/server/server.c src/system/index/index.c src/system/engine/innodb.c src/system/log/checkpoint.c src/system/sql/parser/connector.c src/system/sql/parser/slot/start.c src/system/transaction/transaction.c)