#ifndef SERVER_SHERK_ENGINE_MODULE_INTERCEPTOR_GRANT_INTERCEPTOR_H
#define SERVER_SHERK_ENGINE_MODULE_INTERCEPTOR_GRANT_INTERCEPTOR_H

extern int grant_interceptor_is_able_show();

extern int grant_interceptor_is_able_use();

extern int grant_interceptor_is_able_create_database();

extern int grant_interceptor_is_able_drop_database();

extern int grant_interceptor_is_able_drop_table();

extern int grant_interceptor_is_able_create_table();

extern int grant_interceptor_is_able_delete_table();

extern int grant_interceptor_is_able_desc();


extern int grant_interceptor_is_able_desc_field();

extern int grant_interceptor_is_able_select();

extern int grant_interceptor_is_able_insert();

extern int grant_interceptor_is_able_update();

#endif
