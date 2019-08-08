#include <stdio.h>
#include <stdlib.h>
#include "variable_master.h"
#include <string.h>

// (变量)记忆大师

Variable_Master_Global_Variables variable_master_global_variables;
Variable_Master_Session_Variables variable_master_session_variables;

// 记忆客户端的信息
void variable_master_memory_client(VariableMaster_UserClient user_client) {

    VariableMaster_UserClient *p = &(variable_master_session_variables.user_client);

    p->ip = (NULL != user_client.ip) ? user_client.ip : p->ip;
    p->port = (-1 != user_client.port) ? user_client.port : p->port;

    p->name = (NULL != user_client.name) ? user_client.name : p->name;
    p->password = (NULL != user_client.password) ? user_client.password : p->password;
    p->session = (NULL != user_client.session) ? user_client.session : p->session;

    // printf("-----------p->time:%s,----user_client.time:%s-------",p->time, user_client.time);

    p->time = (NULL != user_client.time) ? user_client.time : p->time;

    p->is_login = (-1 != user_client.is_login) ? user_client.is_login : p->is_login;
}

// 记忆下SQL的信息
void variable_master_memory_sql(VariableMaster_SQLContainer sql_container) {

    VariableMaster_SQLContainer *p = &(variable_master_session_variables.sql_container);

    p->sql = (NULL != sql_container.sql) ? sql_container.sql : p->sql;
    p->sql_len = (0 != sql_container.sql_len) ? sql_container.sql_len : p->sql_len;
    p->sql_category = (-1 != sql_container.sql_category) ? sql_container.sql_category : p->sql_category;

    p->command = (0 != sql_container.command) ? sql_container.command : p->command;
}

// 记忆下配置的信息
void variable_master_memory_config(VariableMaster_ConfigDocker config_docker) {

    VariableMaster_ConfigDocker *p = &(variable_master_session_variables.config_docker);

    p->storage_plan = (NULL != config_docker.storage_plan) ? config_docker.storage_plan : p->storage_plan;
}

// 记忆下数据库的信息
void variable_master_memory_database(VariableMaster_DatabaseVessel database_vessel) {

    VariableMaster_DatabaseVessel *p = &(variable_master_session_variables.database_vessel);

    p->database_name = (NULL != database_vessel.database_name) ? database_vessel.database_name : p->database_name;
}

void variable_master_init_sql(VariableMaster_SQLContainer *sql_container) {

    sql_container->sql = NULL;
    sql_container->sql_len = 0;
    sql_container->sql_category = -1;

    sql_container->command = NULL;

    sql_container->last_sql = NULL;
    sql_container->last_sql_len = 0;
}

void variable_master_init_client(VariableMaster_UserClient *user_client) {

    user_client->ip = NULL;
    user_client->port = -1;

    user_client->name = NULL;
    user_client->password = NULL;
    user_client->session = NULL;

    user_client->is_login = -1;

    user_client->time = NULL;
}

void variable_master_init_config(VariableMaster_ConfigDocker *config_docker) {

    config_docker->storage_plan = NULL;
}

void variable_master_init_database(VariableMaster_DatabaseVessel *database_vessel) {

    database_vessel->database_name = NULL;
}
