#include <stdio.h>

/**退出程序
 *
 * @return int
 */
int exit() {

    printf("你确定要退出程序吗？");
    char ch = getchar();
    return (ch == 'y' || ch == 'Y') ? 1 : 0;
}