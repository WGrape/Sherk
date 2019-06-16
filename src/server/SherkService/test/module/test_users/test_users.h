#ifndef SERVER_SHERK_SERVICE_TEST_MODULE_TEST_USERS_H
#define SERVER_SHERK_SERVICE_TEST_MODULE_TEST_USERS_H

#include <SherkService/mechanism/include/struct/res_array.h>

extern RES_ARRAY *test_users_get_users_username();

extern RES_ARRAY *test_users_get_users_password();

extern void test_users_print_users();

#endif

