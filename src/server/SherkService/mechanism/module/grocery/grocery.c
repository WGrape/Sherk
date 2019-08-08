#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>
#include <time.h>
#include <SherkSupport/src/vendor/encrypter/encrypter.h>
#include <SherkService/mechanism/include/define/color.h>
#include <SherkService/mechanism/module/administrator/administrator.h>
#include <unistd.h>
#include <SherkService/mechanism/include/struct/res_array.h>

// 输出文字信息
void grocery_console_print(char *s) {

}

// 输出红色字体的文字信息
void grocery_console_print_with_red_color(char *s) {

    printf(RED "%s", s);
    printf("\n");
    printf(NONE);
}

// 输出黄色字体的文字信息
void grocery_console_print_with_test_color(char *s) {

    printf(BROWN "%s", s);
}

void grocery_console_print_with_blue_color(char *s) {

    printf(BLUE "%s", s);
    printf("\n");
    printf(NONE);
}

// 输出带颜色的字体
void grocery_console_print_with_color(char *color, char *s) {

}

/**
 * 程序错误退出
 * @param string msg
 */
void grocery_exit_with_error(char *msg) {

    // 使用红色
    grocery_console_print_with_red_color(msg);
    exit(-1);
}


char *grocery_concat_database_location_string(char *databasename) {

    char *path = (char *) malloc(sizeof(char) * 100);
    memset(path, '\0', 100);

    strcat(path, administrator_method_read_config_string_database());
    strcat(path, databasename);
    strcat(path, "/");

    return path;
}

char *grocery_concat_table_frm_location_string(char *databasename, char *tablename) {

    char *path = (char *) malloc(sizeof(char) * 100);
    memset(path, '\0', 100);

    strcat(path, grocery_concat_database_location_string(databasename));
    strcat(path, tablename);
    strcat(path, ".frm");

    return path;
}

char *grocery_concat_table_field_location_string(char *databasename, char *tablename) {

    char *path = (char *) malloc(sizeof(char) * 100);
    memset(path, '\0', 100);

    strcat(path, grocery_concat_database_location_string(databasename));
    strcat(path, tablename);
    strcat(path, ".field");

    return path;
}

char *grocery_concat_table_location_string(char *databasename, char *tablename) {

    char *path = (char *) malloc(sizeof(char) * 100);
    memset(path, '\0', 100);

    strcat(path, grocery_concat_database_location_string(databasename));
    strcat(path, tablename);
    strcat(path, ".table");

    return path;
}

int grocery_is_file_exists(char *file) {

    if (0 == access(file, 0)) {

        return 1;
    }

    return 0;
}

int grocery_is_debug() {

    if (0 != strcmp("debug", administrator_method_read_config_string("environment"))) {

        return 0;
    }

    return 1;
}

/**
 * 去除字符串的两侧空白
 * @param str
 * @return
 */
char *grocery_string_trim(char *str) {

    char *buf1, *buf2;
    int i;
    if (str == NULL) {
        return NULL;
    }

    // 处理字符串前面的空格
    for (buf1 = str; *buf1 && *buf1 == ' '; buf1++);

    // 将去掉前面空格的字符串向前复制
    for (buf2 = str, i = 0; *buf1;) {
        *buf2++ = *buf1++;
        i++;
    }
    *buf2 = '\0';

    // 处理字符串后面的空格
    while (*--buf2 == ' ') {
        *buf2 = '\0';
    }
    return str;
}

char *grocery_string_cutwords(char *page, int start, int end) {
    char *word = malloc(sizeof(char) * 99999); // 必须开大点, 不然会出现很多奇怪的问题
    int pos = 0;
    for (int i = start; i <= end; i++) {
        word[pos++] = page[i];
    }
    word[pos] = '\0';
    return grocery_string_trim(word);
}

char *grocery_string_my_trim(char *str) {

    int i, len = (int) strlen(str);

    int left = 0;
    for (i = 0; i <= len - 1; ++i) {

        if (' ' != str[i]) {

            break;
        }
        left = i;
    }

    int right = len - 1;
    for (i = len - 1; i >= 0; --i) {

        if (' ' != str[i]) {

            break;
        }
        right = i;
    }

    // printf("str:%s---------left:%d------right:%d----\n",str,left,right);
    return grocery_string_cutwords(str, left, right);
}

void grocery_string_tolower(char *str) {
    char *curr = str;
    while (*curr != '\0') {
        //isupper() 判断字母是否为大写
        if (isalpha(*curr) && isupper(*curr)) {
            *curr = tolower(*curr);
        }
        curr++;
    }
}

char *grocery_string_delete_quote(char *str) {

    int i, len = (int) strlen(str);

    for (i = 0; i <= len - 1; ++i) {

        if ('\'' == str[i] || '\"' == str[i]) {

            str[i] = ' ';
        }
    }

    return str;
}

/**
 * 获取字符串在目标字符串中的第一次出现的第一个字符的位置
 * @param string
 * @param str
 * @param exit_if_error
 * @return
 */
int grocery_string_get_str_first_char_index(char *string, char *str, int exit_if_error) {

    char *pos = strstr(string, str);
    if (NULL == pos) {

        if (exit_if_error) {
            grocery_exit_with_error("程序出错");
        }
        return -1;
    }

    return (int) (pos - string);
}

/**
 * 获取字符串在目标字符串中的第一次出现的最后一个字符的位置
 * @param string
 * @param str
 * @param exit_if_error
 * @return
 */
int grocery_string_get_str_last_char_index(char *string, char *str, int exit_if_error) {

    char *pos = strstr(string, str);
    if (NULL == pos) {

        if (exit_if_error) {
            grocery_exit_with_error("程序出错");
        }
        return -1;
    }

    return (int) (pos - string + strlen(str) - 1);
}

/**
 * 获取某个字符在字符串中最后一次出现的位置
 * @param string
 * @param ch
 * @param exit_if_error
 * @return
 */
int grocery_string_get_char_in_string_last_appear_index(char *string, char ch, int exit_if_error) {

    int i, end = -1, len = (int) strlen(string);

    for (i = 0; i <= len - 1; ++i) {

        if (ch == string[i]) {

            end = i;
        }
    }

    if (-1 == end && exit_if_error) {

        grocery_exit_with_error("程序出错");
    }

    return end;
}

/**
 * 获取字符串在目标字符串中的第一次出现的下一个字符的位置
 * @param string
 * @param str
 * @param exit_if_error
 * @return
 */
char *grocery_string_get_str_next_char_address(char *string, char *str, int exit_if_error) {

    char *pos = strstr(string, str);
    if (NULL == pos) {

        if (exit_if_error) {
            grocery_exit_with_error("程序出错");
        }
        return NULL;
    }

    return pos + strlen(str);
}

/**
 * 检查是否是合法字符
 * @param ch
 * @return
 */
int grocery_char_is_legal(char *p) {

    char ch = *p;

    if (ch >= 'A' && ch <= 'z') {

        return 1;
    }

    if (ch >= 'a' && ch <= 'z') {

        return 1;
    }

    if (ch >= '0' && ch <= '9') {

        return 1;
    }

    return 0;
}

/**
 * 获取字符串在目标字符串中的第一次出现的下一个非空格字符从位置
 * @param string
 * @param str
 * @param exit_if_error
 * @return
 */
char *grocery_string_get_str_next_not_white_char_address(char *string, char *str, int exit_if_error) {

    char *pos = strstr(string, str);
    if (NULL == pos) {

        if (exit_if_error) {
            grocery_exit_with_error("程序出错");
        }
        return NULL;
    }

    char *p = pos + strlen(str);

    while (0 == grocery_char_is_legal(p)) {
        ++p;
    }
    return p;
}

/**
 * 用空格切割字符串, 如 "hello   world" 应该返回 "hello" 和 "world"
 * @param string
 * @return
 */
char **grocery_string_split_by_whitespace_into_two_part(char *string) {

    int i, len = (int) strlen(string);

    int first_meet_whitespace = -1, last_meet_whitespace = -1;


    for (i = 0; i <= len - 1; ++i) {

        if (' ' == string[i] || '\n' == string[i] || '\t' == string[i]) {

            if (-1 == first_meet_whitespace) {

                first_meet_whitespace = i;
            }

            last_meet_whitespace = i;
        }
    }

    if (0 == first_meet_whitespace) {

        first_meet_whitespace = 1;
    }

    char *s1 = grocery_string_cutwords(string, 0, first_meet_whitespace - 1);
    char *s2 = &string[last_meet_whitespace + 1];
    // printf("first_meet_whitespace:%d, last_meet_whitespace:%d\n", first_meet_whitespace, last_meet_whitespace);

    char *s[2]; //  char **s = (char**)malloc(sizeof(char**)*2);
    // char **s = (char **) malloc(sizeof(char **) * 2);

    s[0] = s1;
    s[1] = s2;

    // printf("----s[0]:%s---s[0]:%s--\n", s[0], s[1]);
    return s;
}

/**
 * 取代 grocery_string_split_by_whitespace_into_two_part 方法, 支持更多的字符
 * @param string
 * @param ch
 * @return
 */
char **grocery_string_split_by_char_into_two_part(char *string, char ch) {

    int i, len = (int) strlen(string);

    int first_meet_char = -1, last_meet_char = -1;


    for (i = 0; i <= len - 1; ++i) {

        if (ch == string[i]) {

            if (-1 == first_meet_char) {

                first_meet_char = i;
            }

            last_meet_char = i;
        }
    }

    if (0 == first_meet_char) {

        first_meet_char = 1;
    }

    char *s1 = grocery_string_cutwords(string, 0, first_meet_char - 1);
    char *s2 = &string[last_meet_char + 1];
    // printf("first_meet_char:%d, last_meet_char:%d\n", first_meet_char, last_meet_char);

    char *s[2]; //  char **s = (char**)malloc(sizeof(char**)*2);
    // char **s = (char **) malloc(sizeof(char **) * 2);

    s[0] = s1;
    s[1] = s2;

    // printf("----s[0]:%s---s[0]:%s--\n", s[0], s[1]);
    return s;
}

/**
 * 从两边夹逼, 提取字符串, 如获取一个字符串中第2个','和第5个','之间的字符串, grocery_string_crimp(s,',',2,',',5)
 * @param string
 * @param left_char
 * @param left_char_appear_th
 * @param right_char
 * @param right_char_appear_th
 * @return
 */
char *
grocery_string_crimp(char *string, char left_char, int left_char_appear_th, char right_char, int right_char_appear_th) {

    int i, len = (int) strlen(string);

    int left_char_appear_times = 0, right_char_appear_times = 0;

    int left_pos = -1, right_pos = -1;

    for (i = 0; i <= len - 1; ++i) {

        if (left_char == string[i]) {

            left_char_appear_times++;
        }

        if (left_char_appear_th == left_char_appear_times && -1 == left_pos) {
            left_pos = i;
        }

        if (right_char == string[i]) {

            right_char_appear_times++;
        }

        if (right_char_appear_th == right_char_appear_times && -1 == right_pos) {

            right_pos = i;
        }
    }

    // printf("left_pos:%d, right_pos:%d\n", left_pos, right_pos);
    return grocery_string_cutwords(string, left_pos + 1, right_pos - 1);
}

/**
 * 统计字符在字符串中出现的次数
 * @param string
 * @param ch
 * @return
 */
int grocery_char_in_string_appear_times(char *string, char ch) {

    int i, len = (int) strlen(string), times = 0;

    for (i = 0; i <= len - 1; ++i) {

        if (ch == string[i]) {

            ++times;
        }
    }

    return times;
}

void grocery_time_tostring(char *_time) {

    time_t timestamp;
    time(&timestamp);
    // printf("%ld",timestamp);
    struct tm *timeinfo = localtime(&timestamp);
    strftime(_time, sizeof(char) * 20, "%Y-%m-%d %H:%M:%S", timeinfo); // 注意: 写成sizeof(_time)是错误的
}

struct tm* grocery_time_tostruct() {

    time_t timestamp;
    time(&timestamp);
    struct tm *timeinfo = localtime(&timestamp);
    return timeinfo;
}

char *grocery_time_get_now() {

    char *_time = (char *) malloc(sizeof(char) * 20);
    grocery_time_tostring(_time);

    return _time;
}

int grocery_get_random_int(int x, int y) {

    // 生成随机的字段数和记录数
    // srand((unsigned) time(NULL));
    // int record_counts = (rand() % (10 - 1)) + 1; // 生成 1 - 10 随机数
    // int field_counts = (rand() % (5 - 2)) + 2; // 生成 2 - 5 随机数
    // for(int i=1;i<=100;++i){ printf("---%d---\n",(rand() % (1000 - 1)) + 1); }
    return (rand() % (y - x)) + x;
}

char *grocery_get_random_md5_string() {

    char _time[20];
    grocery_time_tostring(_time);

    char string[100];
    sprintf(string, "%d-%s", grocery_get_random_int(10, 999999), _time);

    return MDString(string);
}


char *grocery_get_random_md5_string_6() {

    return grocery_string_cutwords(grocery_get_random_md5_string(), 0, 6);
}

/**
 * 返回元素在数组中的下标( 字符串数组 )
 * @param array
 * @param item
 * @param count 数组个数
 * @return
 */
int grocery_string_item_in_array_index(char **array, char *item, int count) {

    int i;

    for (i = 0; i <= count - 1; ++i) {

        if (0 == strcmp(item, array[i])) {

            return i;
        }
    }

    // 不存在数组中
    return -1;
}


char **grocery_string_explode_by_str(char *string, char *str) {


}

RES_ARRAY *grocery_string_explode_by_char(char *string, char ch) {

    RES_ARRAY *res_array = (RES_ARRAY *) malloc(sizeof(RES_ARRAY) * 1);
    int count = 0;

    char **array = (char **) malloc(sizeof(char *) * 100);

    int i, len = (int) strlen(string);
    int start = 0, end = 0;
    for (i = 0; i <= len - 1; ++i) {

        end = i;
        if (ch == string[i]) {

            array[count] = grocery_string_cutwords(string, start, end - 1);
            ++count;
            start = end + 1;
        }
    }

    // 最后一个, 如: SHOW,CREATE,DROP,INSERT,DELETE,UPDATE,SELECT
    array[count] = grocery_string_cutwords(string, start, len - 1);

    res_array->array = array;
    res_array->count = count;
    return res_array;
}

// 删除换行符
char *grocery_string_delete_enter(char *string) {

    if ('\n' == string[strlen(string) - 1]) {

        string[strlen(string) - 1] = '\0';
    }

    return string;
}


