#ifndef SERVER_SHERK_STORAGE_VENDOR_STORAGE_SERIALIZATION_MODULE_BOOK_WORM_H
#define SERVER_SHERK_STORAGE_VENDOR_STORAGE_SERIALIZATION_MODULE_BOOK_WORM_H

extern char *bookworm_read_x_line(char *file, int x_line);

extern void bookworm_write_line(char *file, char *line);

extern void bookworm_write(char *file, char *text);

#endif
