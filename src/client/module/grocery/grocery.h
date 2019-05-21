#ifndef SERVER_SHERK_MECHANISM_MODULE_GROCERY_H
#define SERVER_SHERK_MECHANISM_MODULE_GROCERY_H

extern void grocery_console_print(char *s);

extern void grocery_console_print_with_red_color(char *s);

extern void grocery_console_print_with_blue_color(char *s);

extern void grocery_console_print_with_color();

extern void grocery_exit_with_error(char *msg);

extern int grocery_is_file_exists(char *file);

extern char *grocery_read_file(char *file);

extern char * grocery_get_password_file(char *name);


#endif
