#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SherkSupport/src/module/maintainer/callback/infoschema_callback/infoschema_callback.h>
#include <SherkService/mechanism/module/variable_master/variable_master.h>
#include <SherkSupport/src/module/maintainer/database_in_disk_maintainer/database_in_disk_maintainer.h>
#include <SherkService/test/module/test_database/test_database.h>

extern Variable_Master_Session_Variables variable_master_session_variables;

/**
 * Servlet: show databases
 */
void database_servlet_show_databases(){

    test_database_print_databases();
}

/**
 * Servlet: use database
 * @param database
 */
void database_servlet_use_database(char *database) {

    // 让记忆大师去记忆
    VariableMaster_DatabaseVessel database_vessel;
    variable_master_init_database(&database_vessel);
    char *memory = (char *) malloc(sizeof(char) * 30);
    strcpy(memory, database);
    database_vessel.database_name = memory;
    variable_master_memory_database(database_vessel);
}

/**
 * Servlet: create database
 * @param database
 */
void database_servlet_create_database(char *database) {

    // 判断是否已经存在

    // Disk 操作: create database
    database_in_disk_maintainer_create_database(database, INFOSCHEMA_CALLBACK_ABLE);
}

/**
 * Servlet: drop database
 * @param database
 */
void database_servlet_drop_database(char *database) {

    // Disk 操作: drop database
    database_in_disk_maintainer_drop_database(database, INFOSCHEMA_CALLBACK_ABLE);
}



