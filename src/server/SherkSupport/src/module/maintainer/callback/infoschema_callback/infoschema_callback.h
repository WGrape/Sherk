#ifndef SERVER_SHERK_SUPPORT_MODULE_MAINTAINER_CALLBACK_INFOSCHEMA_CALLBACK_H
#define SERVER_SHERK_SUPPORT_MODULE_MAINTAINER_CALLBACK_INFOSCHEMA_CALLBACK_H

extern const int INFOSCHEMA_CALLBACK_ABLE;
extern const int INFOSCHEMA_CALLBACK_DISABLE;

extern void infoschema_callback_active(int id, char *database_name, char *table_name, char *user_name, char *password,
                                  char *encryption, char *time);

#endif
