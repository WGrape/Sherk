#include <stdio.h>
#include <string.h>
#include <SherkSupport/src/module/maintainer/database_in_disk_maintainer/database_in_disk_maintainer.h>


void test_database_print_databases() {

    printf("\n");
    printf("--------------------------------------------------\n");
    printf("| The Databases \n");
    printf("--------------------------------------------------");


    FILE *fp = database_in_disk_maintainer_show_databases(0);
    char szTest[1000] = {0};

    while (!feof(fp)) {
        memset(szTest, 0, sizeof(szTest));
        fgets(szTest, sizeof(szTest) - 1, fp); // 包含了换行符

        if ('\n' == szTest[strlen(szTest) - 1]) {
            szTest[strlen(szTest) - 1] = '\0';
        }

        if (0 == strcmp("temp_show_databases.txt", szTest) || strlen(szTest) < 1) {

            continue;
        }

        printf("\n| %s", szTest);
    }
    fclose(fp);
    database_in_disk_maintainer_show_databases(1);

    printf("\n--------------------------------------------------\n");

}
