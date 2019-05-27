#include <stdio.h>
#include <string.h>
#include <SherkSQL/src/module/parser/parser.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <SherkService/mechanism/include/define/color.h>

static int automated_times = 1;

void automated_test_print_sql(int i, char *sql) {

    printf(WHITE "\n\nCase %d: sql = %s", i, sql);
    printf(BROWN);
}

void automated_test_start(char *title) {

    printf(BROWN "\n\nThe %dth: %s\n", automated_times, title);
    ++automated_times;
    grocery_console_print_with_test_color("+++++++++++++++++++++++++++++++++++++++++++++++\n");
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

    int i = 0;
    char sql[20][100] = {

            "show users", // 先查看一下系统的用户
            "show network", // 先看一下网络链路
            "show databases", // 先看一下所有的数据库
            "create database test", // 我们先临时创建一个数据库
            "use information_schema",// 在系统表里面看下数据库是否添加进去

            "select * from databases_manage",
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
            "select * from test", // 查看 test 表全部内容

//            "delete table test",// test:
    };

    char sql2[3][100] = {

            "use test",
            "drop table test",
            "drop database test",
    };

    char sql3[7][100] = {

            "use information_schema",
            "drop table users",
            "drop table databases_manage",
            "drop table tables_manage",

            "create table users",
            "create table databases_manage",
            "create table tables_manage",
    };

    if (0 == cmd) {

        automated_test_start("完整测试过程");
        for (; i <= 19; ++i) {

            automated_test_print_sql(i, sql[i]);
            parser_match_sql(sql[i]);
        }
    } else if (1 == cmd) {

        // clear
        automated_test_start("清空遗留的测试数据");
        for (; i <= 2; ++i) {

            automated_test_print_sql(i, sql2[i]);
            parser_match_sql(sql2[i]);
        }
    } else if (2 == cmd) {

        // reload, 重新加载系统
        automated_test_start("重新更正加载系统表");
        for (; i <= 6; ++i) {

            automated_test_print_sql(i, sql3[i]);
            parser_match_sql(sql3[i]);
        }
    }

    automated_test_end();
}

