#ifndef SERVER_SHERK_SERVICE_MECHANISM_MODULE_ADMINISTRATOR_H
#define SERVER_SHERK_SERVICE_MECHANISM_MODULE_ADMINISTRATOR_H

#include <libconfig.h>

extern config_t *administrator_method_get_config();

extern void administrator_method_init_config();

extern char *administrator_method_read_config_string(const char *path);

extern int administrator_method_read_config_int(const char *path);

extern char *administrator_method_read_config_string_database();

#endif
