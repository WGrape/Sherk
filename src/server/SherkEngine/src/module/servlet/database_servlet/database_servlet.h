#ifndef SERVER_SHERK_ENGINE_MODULE_SERVLET_DATABASE_SERVLET_H
#define SERVER_SHERK_ENGINE_MODULE_SERVLET_DATABASE_SERVLET_H

extern void database_servlet_show_databases();

extern void database_servlet_use_database(char *database);

extern void database_servlet_create_database(char *database);

extern void database_servlet_drop_database(char *database);


#endif
