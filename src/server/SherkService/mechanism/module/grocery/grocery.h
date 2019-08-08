#ifndef SERVER_SHERK_SERVICE_MECHANISM_MODULE_GROCERY_H
#define SERVER_SHERK_SERVICE_MECHANISM_MODULE_GROCERY_H

#include <SherkService/mechanism/include/struct/res_array.h>

extern void grocery_console_print(char *s);

extern void grocery_console_print_with_red_color(char *s);

extern void grocery_console_print_with_test_color(char *s);

extern void grocery_console_print_with_blue_color(char *s);

extern void grocery_console_print_with_color(char *color, char *s);

extern void grocery_exit_with_error(char *msg);

extern char *grocery_concat_database_location_string(char *databasename);

extern char *grocery_concat_table_frm_location_string(char *databasename, char *tablename);

extern char *grocery_concat_table_field_location_string(char *databasename, char *tablename);

extern char *grocery_concat_table_location_string(char *databasename, char *tablename);

extern int grocery_is_file_exists(char *file);

extern int grocery_is_debug();

extern char *grocery_string_cutwords(char *page, int start, int end);

extern char *grocery_string_my_trim(char *str);

extern void grocery_string_tolower(char *str);

extern char *grocery_string_delete_quote(char *str);

extern char *grocery_string_trim(char *str);

extern int grocery_string_get_str_first_char_index(char *string, char *str, int exit_if_error);

extern int grocery_string_get_str_last_char_index(char *string, char *str, int exit_if_error);

extern int grocery_string_get_char_in_string_last_appear_index(char *string, char ch, int exit_if_error);

extern char *grocery_string_get_str_next_char_address(char *string, char *str, int exit_if_error);

extern char *grocery_string_get_str_next_not_white_char_address(char *string, char *str, int exit_if_error);

extern char **grocery_string_split_by_whitespace_into_two_part(char *string);

extern char **grocery_string_split_by_char_into_two_part(char *string, char ch);

extern char *
grocery_string_crimp(char *string, char left_char, int left_char_appear_th, char right_char, int right_char_appear_th);

extern int grocery_char_in_string_appear_times(char *string, char ch);

extern void grocery_time_tostring(char *_time);

extern struct tm* grocery_time_tostruct();

extern char *grocery_time_get_now();

extern char *grocery_get_random_md5_string();

extern char *grocery_get_random_md5_string_6();

extern int grocery_string_item_in_array_index(char **array, char *item, int count);

extern int grocery_get_random_int(int x, int y);

extern RES_ARRAY *grocery_string_explode_by_char(char *string, char ch);

extern char *grocery_string_delete_enter(char *string);

#endif
