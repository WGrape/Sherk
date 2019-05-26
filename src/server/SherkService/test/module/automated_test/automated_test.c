#include <stdio.h>
#include <string.h>
#include <SherkSQL/src/module/parser/parser.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <SherkService/mechanism/include/define/color.h>

void automated_test_print_sql(int i, char *sql) {

    printf(RED "\n\nCase %d: sql = %s", i, sql);
    printf(BROWN);
}

void automated_test_start() {

    grocery_console_print_with_test_color("\n\n+++++++++++++++++++++++++++++++++++++++++++++++\n");
    grocery_console_print_with_test_color("| Automated Test Start ->                     |\n");
    grocery_console_print_with_test_color("+++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void automated_test_end() {

    grocery_console_print_with_test_color("\n\n+++++++++++++++++++++++++++++++++++++++++++++++\n");
    grocery_console_print_with_test_color("| Automated Test End <-                       |\n");
    grocery_console_print_with_test_color("+++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf(NONE);
}

void automated_test_main(int cmd) {

    automated_test_start();

    int i = 0;
    char sql[17][100] = {

            "show network", // 先看一下网络链路
            "show databases", // 先看一下所有的数据库
            "create database test", // 我们先临时创建一个数据库
            "show databases", // 再展示一下所有数据库, 发现数据库已经添加了
            "show tables", // 看一下所有的数据表, 咦, 提示需要先选中数据库

            "use test", // 好吧，我们就先使用刚才创建的那个数据库
            "show variables", // 发现会话变量中的 database 确实已经有了
            "show tables", // 再看一下所有的数据表, 发现此时库内数据表为空
            "create table test", // 创建一个 test 数据表
            "show tables", // 再看一下全部的数据表, 发现数据表已经生成了, 我们去本地存储发现多了3个文件 : test.frm, test.field, test.table

            "desc table test", // 看一下 test 表的结构信息
            "desc table field test", // 看一下 test 表的字段信息
            "select * from test", // 查看 test 表全部内容
            "select table test",// test:
            "insert table test",// test:

            "update table test",// test:
            "delete table test",// test:
    };

    char sql2[3][100] = {

            "use test",
            "drop table test",
            "drop database test",
    };

    if (0 == cmd) {

        for (; i <= 16; ++i) {

            if (0 == strcmp("select table", grocery_string_cutwords(sql[i], 0, 11))) {

            } else if (0 == strcmp("insert table", grocery_string_cutwords(sql[i], 0, 11))) {

            } else if (0 == strcmp("update table", grocery_string_cutwords(sql[i], 0, 11))) {

            } else if (0 == strcmp("delete table", grocery_string_cutwords(sql[i], 0, 11))) {

            } else {
            }

            automated_test_print_sql(i, sql[i]);
            parser_match_sql(sql[i]);
        }
    } else if (1 == cmd) {

        // clear
        for (; i <= 2; ++i) {

            automated_test_print_sql(i, sql2[i]);
            parser_match_sql(sql2[i]);
        }
    }

    automated_test_end();
}

