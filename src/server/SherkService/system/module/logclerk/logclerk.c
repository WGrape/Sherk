#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <SherkService/mechanism/module/administrator/administrator.h>

const int LOGCLERK_LOG_LEVEL_DEBUG = 1;
const int LOGCLERK_LOG_LEVEL_ERROR = 2;
const int LOGCLERK_LOG_LEVEL_ACCESS = 3;
const int LOGCLERK_LOG_LEVEL_SQL_QUERY = 4;
const int LOGCLERK_LOG_LEVEL_SQL_SLOW = 5;
const int LOGCLERK_LOG_LEVEL_SQL_BIN = 6;

static int log_count;

void logclerk_set_time(char *_time, char *_time_format, int len) {

    time_t timestamp;
    time(&timestamp);
    // printf("%ld",timestamp);
    struct tm *timeinfo = localtime(&timestamp);
    strftime(_time, sizeof(char)*len, _time_format, timeinfo); // 注意: 写成sizeof(_time)是错误的
}

void logclerk_set_header(char *header) {

    logclerk_set_time(header, "------------ %Y-%m-%d %H:%M:%S ------------", 50);
    strcat(header,"\n\n");
}

void logclerk_set_footer(char *footer) {

    strcat(footer, "\n\n");
}

void logclerk_write(int log_level, char *log) {

    const char *log_dir_root = administrator_method_read_config_string("app.server.dir.root");
    const char *log_dir_home = administrator_method_read_config_string("app.server.dir.log.home");

    const char *log_file = strcat((char *) log_dir_root, log_dir_home); // (char *)强转一下就不会提示错误了

    const char *log_level_path;
    switch (log_level) {

        case LOGCLERK_LOG_LEVEL_DEBUG:
            log_level_path = administrator_method_read_config_string("app.server.dir.log.level.debug");
            break;

        case LOGCLERK_LOG_LEVEL_ERROR:
            log_level_path = administrator_method_read_config_string("app.server.dir.log.level.error");
            break;

        case LOGCLERK_LOG_LEVEL_ACCESS:
            log_level_path = administrator_method_read_config_string("app.server.dir.log.level.access");
            break;

        case LOGCLERK_LOG_LEVEL_SQL_QUERY:
            log_level_path = administrator_method_read_config_string("app.server.dir.log.sql.query");
            break;

        case LOGCLERK_LOG_LEVEL_SQL_SLOW:
            log_level_path = administrator_method_read_config_string("app.server.dir.log.sql.slow");
            break;

        case LOGCLERK_LOG_LEVEL_SQL_BIN:
            log_level_path = administrator_method_read_config_string("app.server.dir.log.sql.bin");
            break;

        default:
            log_level_path = "";
            break;
    }
    strcat((char *) log_file, log_level_path);

    // 生成文件名
    char filename[50];
    logclerk_set_time(filename, "%Y%m%d-%H-%M", 50);
    strcat(filename, ".log");

    // 定位日志文件
    strcat((char *) log_file, filename);

    // 给日志加上日志头和日志尾
    char padding[555];
    char header[50];
    char footer[50];
    logclerk_set_header(header);
    logclerk_set_footer(footer);
    strcat(padding, header);
    strcat(padding, log);
    strcat(padding, footer);

    FILE *fp = fopen(log_file, "a+"); // a+会append
    fprintf(fp, "%s", padding);
    fclose(fp);// 必须close才能顺利写入文件
}

void logclerk_write_slow_query_log(long start_point, long end_point){

    // 是否开启慢查询日志

    // 判断时间间隔是否大于配置的慢查询时间
}
