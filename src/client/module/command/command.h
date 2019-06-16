#ifndef CLIENT_MODULE_COMMAND_H
#define CLIENT_MODULE_COMMAND_H

extern int command_login_success(int argc, char **argv);

extern int command_enter_sql_interactive_env();

extern int command_logout_success(int exit_signal);

#endif
