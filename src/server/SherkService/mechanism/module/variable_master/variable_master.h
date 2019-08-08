#ifndef SERVER_SHERK_SERVICE_MECHANISM_MODULE_VARIABLE_MASTER_H
#define SERVER_SHERK_SERVICE_MECHANISM_MODULE_VARIABLE_MASTER_H

typedef struct VariableMaster_UserClient{

    char *name;
    char *password;
    char *ip;
    int port;
    char *session; // 登录则有session=md5(name+ip+password), 非登录则为NULL
    int is_login; // 是否已经登录

    char *time; // 时间

}VariableMaster_UserClient;

typedef struct VariableMaster_SQLContainer{

    char *last_sql; // 上一条SQL
    size_t last_sql_len; // 上一条SQL长度

    char *sql; // 记录当前的SQL
    size_t sql_len; // 当前SQL长度
    int sql_category; // sql分类

    char *command; // Sherk命令

}VariableMaster_SQLContainer;

typedef struct VariableMaster_ConfigDocker{


    char *storage_plan;
}VariableMaster_ConfigDocker;

// 主要是存储数据库的信息
typedef struct VariableMaster_DatabaseVessel{

    char *database_name; // 当前所在的数据库
}VariableMaster_DatabaseVessel;

// 全局变量
typedef struct Variable_Master_Global_Variables{


}Variable_Master_Global_Variables;

// session 变量
typedef struct Variable_Master_Session_Variables{

    VariableMaster_UserClient user_client;
    VariableMaster_SQLContainer sql_container;
    VariableMaster_ConfigDocker config_docker;
    VariableMaster_DatabaseVessel database_vessel;

}Variable_Master_Session_Variables;

extern void variable_master_memory_client(VariableMaster_UserClient user_client);

extern void variable_master_memory_sql(VariableMaster_SQLContainer sql_container);

extern void variable_master_memory_config(VariableMaster_ConfigDocker config_docker);

extern void variable_master_memory_database(VariableMaster_DatabaseVessel database_vessel);

extern void variable_master_init_sql(VariableMaster_SQLContainer *sql_container);

extern void variable_master_init_client(VariableMaster_UserClient *user_client);

extern void variable_master_init_config(VariableMaster_ConfigDocker *config_docker);

extern void variable_master_init_database(VariableMaster_DatabaseVessel *database_vessel);

#endif
