#ifndef SERVER_SHERK_SERVICE_MECHANISM_MODULE_EXCEL_GRAPH_H
#define SERVER_SHERK_SERVICE_MECHANISM_MODULE_EXCEL_GRAPH_H

#include <stdio.h>

extern FILE *excel_graph_create_file(char *file);

extern void excel_graph_draw_enter(FILE *fp);

extern void excel_graph_draw_box_top(FILE *fp, int width);

extern void excel_graph_draw_box_aside(FILE *fp, char *text, int width, int length);

extern void excel_graph_draw_box_bottom(FILE *fp, int width);

#endif
