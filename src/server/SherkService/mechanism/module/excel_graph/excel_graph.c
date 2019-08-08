#include <stdio.h>


/* -------------- 使用例子 --------------
 FILE *fp = fopen(".excel_graph.txt", "w+");

 int width = 10;
 char *text = "name";
 int length = (int)strlen(text);
 excel_graph_draw_box_top(fp, width);
 excel_graph_draw_enter(fp);
 excel_graph_draw_box_aside(fp, text, width,length);
 excel_graph_draw_enter(fp);
 excel_graph_draw_box_bottom(fp, width);
*-------------- 使用例子 --------------*/

/**
 * 创建文件
 * @param file
 * @return
 */
FILE *excel_graph_create_file(char *file) {

    FILE *fp = fopen(file, "w+");

    return fp;
}

/**
 * 绘制回车
 * @param fp
 */
void excel_graph_draw_enter(FILE *fp) {

    fprintf(fp, "%c", '\n');
}

/**
 * 绘制方框的顶部
 * @param line_num/width 横线数量
 */
void excel_graph_draw_box_top(FILE *fp, int width) {

    width = (width > 0) ? width : 1;

    int i = 0;

    char s[9999];

    s[0] = '+';

    for (i = 1; i <= width; ++i) {

        s[i] = '-';
    }

    s[i] = '+';

    fprintf(fp, "%s", s);
}

/**
 * 绘制方框的两侧
 * @param fp
 * @param text
 * @param width
 * @param length
 */
void excel_graph_draw_box_aside(FILE *fp, char *text, int width, int length) {

    int left_blank_num = 0, right_blank_num = 0; // 字符串需要绘制的左边和右边的空白数

    left_blank_num = (width - length) / 2;
    right_blank_num = width - length - left_blank_num;

    int i = 1;
    char s[9999];

    // 绘制字符左边
    s[0] = '|';
    for (i = 1; i <= left_blank_num; ++i) {

        s[i] = ' ';
    }
    s[i] = '\0';
    fprintf(fp, "%s", s);

    // 绘制字符
    fprintf(fp, "%s", text);

    // 绘制字符右边
    for (i = 0; i <= right_blank_num - 1; ++i) {

        s[i] = ' ';
    }
    s[i] = '|';
    s[i + 1] = '\0';
    fprintf(fp, "%s", s);

}

/**
 * 绘制方框的底部
 * @param fp
 * @param width
 */
void excel_graph_draw_box_bottom(FILE *fp, int width) {

    excel_graph_draw_box_top(fp, width);
}


