#ifndef SERVER_SHERK_SQL_MODULE_PARSER_H
#define SERVER_SHERK_SQL_MODULE_PARSER_H

extern const int SQL_MAX_PATTRENS;

extern const int SQL_CATEGORY_IS_SHERK_COMMAND;
extern const int SQL_CATEGORY_IS_SQL;
extern const int SQL_CATEGORY_IS_SHERK_COMMAND_IN_SQL;
extern const int SQL_TYPE_IS_CREATE_DATABASE;
extern const int SQL_TYPE_IS_CREATE_TABLE;

extern const int SQL_TYPE_IS_DROP_DATABASE;

extern char *parser_match_sql(char *sql);

extern int parser_match_regex(const char *pattern, const char *sql);

extern char *parser_exec(char *sql);

#endif
