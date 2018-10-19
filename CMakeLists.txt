cmake_minimum_required(VERSION 3.10)
project(Sherk C)

set(CMAKE_C_STANDARD 99)

add_executable(Sherk

        main.c
        src/include/algorithm/Btree/B+tree.h
        launcher/client.lanch.c
        launcher/server.lanch.c
        src/server/system/index/index.c

        src/server/system/engine/innodb.c
        src/server/system/sql/parser/connector.c
        src/server/system/sql/parser/slot/start.c
        src/server/kernel/transaction/transaction.c
        src/server/system/charset/charset.c
        src/server/security/mechanism/role/role.c
        src/server/security/mechanism/identity/identity.c
        src/server/security/mechanism/accessControl/accessControl.c
        src/server/security/mechanism/throne/grant/grant.c
        src/server/security/mechanism/throne/revoke/revoke.c
        src/server/security/encrypt/encrypt.c
        src/server/kernel/recovery/recovery.c
        src/server/kernel/concurrency/locking/semaphore.c
        src/include/define/define.c
        src/server/security/view/view.c
        src/server/security/audit/audit.c
        src/server/integrity/integrity.c

        src/server/server.c
        src/client/client.c


        src/server/integrity/assertion/assertion.c


)
