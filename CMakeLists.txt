cmake_minimum_required(VERSION 3.10)
project(Sherk C)

set(CMAKE_C_STANDARD 99)

add_executable(Sherk main.c main.c src/include/algorithm/Btree/B+tree.h client/client.c server/server.c src/system/index/index.c src/system/engine/innodb.c src/system/sql/parser/connector.c src/system/sql/parser/slot/start.c src/kernel/transaction/transaction.c src/system/charset/charset.c src/security/mechanism/role/role.c src/security/mechanism/identity/identity.c src/security/mechanism/accessControl/accessControl.c src/security/mechanism/throne/grant/grant.c src/security/mechanism/throne/revoke/revoke.c src/security/encrypt/encrypt.c src/kernel/recovery/recovery.c src/kernel/concurrency/locking/semaphore.c src/include/define/define.c src/security/view/view.c src/security/audit/audit.c src/integrity/integrity.c)