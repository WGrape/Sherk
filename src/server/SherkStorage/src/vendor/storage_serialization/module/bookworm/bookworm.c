#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SherkSupport/src/module/skeleton/skeleton.h>

/**
 * 读取某行 (从1开始, 不是从0开始)
 * @param file
 * @param line
 * @return
 */
char *bookworm_read_x_line(char *file, int x_line) {

    // 是否找到
    int find = 0;

    // 先读第1行
    int i = 1;
    FILE *fp = fopen(file, "r");
    char *record = (char *) malloc(sizeof(char) * RECORD_JSON_MAX_LEN);
    memset(record, '\0', sizeof(char) * RECORD_JSON_MAX_LEN);
    char *file_pos_pointer = fgets(record, RECORD_JSON_MAX_LEN, fp);

    // 再接着向下读
    while (x_line != i && NULL != file_pos_pointer) {

        memset(record, '\0', sizeof(char) * RECORD_JSON_MAX_LEN);

        // 读第 i 行
        ++i;
        file_pos_pointer = fgets(record, RECORD_JSON_MAX_LEN, fp);
    }

    // 找到了
    if(i == x_line && NULL != file_pos_pointer){ // 必须 NULL != file_pos_pointer

        find = 1;
    }

    // 如果没有找到, 则返回 NULL
    if(0 == find){

        return NULL;
    }

    return record;
}

/**
 * 写入一行
 * @param file
 * @param line
 */
void bookworm_write_line(char *file, char *line) {

    FILE *fp = fopen(file, "a+"); // a+ 追加, 不存在则创建
    fputs(line, fp);
    fclose(fp); // 必须close, 否则无法写入
}

/**
 * 覆盖写入
 * @param file
 * @param line
 */
void bookworm_write(char *file, char *text) {

    // 先清空文件内容, 之所以这样是防止 text 为空时没有写入, 造成未清空
    FILE *fp = fopen(file, "w+");
    fclose(fp);

    fp = fopen(file, "w+"); // w+ 覆盖写入, 不存在则创建
    fputs(text, fp);
    fclose(fp); // 必须close, 否则无法写入
}

// 读当前的行数

