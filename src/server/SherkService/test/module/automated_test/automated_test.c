#include <stdio.h>
#include <SherkSQL/src/module/parser/parser.h>
#include <SherkService/mechanism/module/grocery/grocery.h>
#include <SherkService/mechanism/include/define/color.h>


void automated_test_start() {

    grocery_console_print_with_test_color("\n\n+++++++++++++++++++++++++++++++++++++++++++++++\n");
    grocery_console_print_with_test_color("| Automated Test Start \n");
    grocery_console_print_with_test_color("+++++++++++++++++++++++++++++++++++++++++++++++\n");
}

void automated_test_end() {

    grocery_console_print_with_test_color("\n\n+++++++++++++++++++++++++++++++++++++++++++++++\n");
    grocery_console_print_with_test_color("| Automated Test End \n");
    grocery_console_print_with_test_color("+++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf(NONE);
}

void automated_test_main() {

    automated_test_start();

    int i = 0;
    char sql[5][100] = {

            "show databases",
            "use test_database",
            "show variables",
            "show tables",
    };

    for (; i <= 4; ++i) {

        parser_match_sql(sql[i]);
    }

    automated_test_end();
}

