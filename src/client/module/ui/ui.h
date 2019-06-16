#ifndef CLIENT_MODULE_UI_H
#define CLIENT_MODULE_UI_H

// 暴露给外界的接口

#include "include/object/User.h"

extern User ui_print_login_dialog();

extern void ui_print_welcome();

extern void ui_print_illegal_input();

extern void ui_print_wait_for_input(char *sql);

extern void ui_print_logo();

extern void ui_print_bye();

extern void ui_print_account_not_exist();

extern void ui_print_sql_response_data(char *buffer);

#endif
