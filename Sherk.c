#include <stdio.h>

//#include "src/launcher/client.launcher.c"
//#include "src/launcher/server.launcher.c"


// 主程序
int main(int argc, char *argv[]) {

    int i;

    printf("the count of args is %d \n", argc-1);

    for (i = 2; i <= argc; i++) {

        printf("%s ", argv[i-1]);
    }

    printf("sherk > ");

    getchar();

    return 0;
}
