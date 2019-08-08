#ifndef SERVER_SHERK_SERVICE_SYSTEM_MODULE_LOGCLERK_H
#define SERVER_SHERK_SERVICE_SYSTEM_MODULE_LOGCLERK_H

extern void logclerk_write(int log_level, char *log);

extern void logclerk_write_slow_query_log(long start_point, long end_point);

#endif
