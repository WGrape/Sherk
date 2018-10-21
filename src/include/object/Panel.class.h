#include <stdio.h>

// 控制面板
typedef struct Panel {

    // 打印logo
    static void (*printLogo)();

    static int (*exit)();

} Panel;


static void printLogo() {

    printf("                                                     \n"
           "                                                     \n"
           "  .--.--.     ,---,                             ,-.  \n"
           " /  /    '. ,--.' |                         ,--/ /|  \n"
           "|  :  /`. / |  |  :                __  ,-.,--. :/ |  \n"
           ";  |  |--`  :  :  :              ,' ,'/ /|:  : ' /   \n"
           "|  :  ;_    :  |  |,--.   ,---.  '  | |' ||  '  /    \n"
           " \\  \\    `. |  :  '   |  /     \\ |  |   ,''  |  :    \n"
           "  `----.   \\|  |   /' : /    /  |'  :  /  |  |   \\   \n"
           "  __ \\  \\  |'  :  | | |.    ' / ||  | '   '  : |. \\  \n"
           " /  /`--'  /|  |  ' | :'   ;   /|;  : |   |  | ' \\ \\ \n"
           "'--'.     / |  :  :_:,''   |  / ||  , ;   '  : |--'  \n"
           "  `--'---'  |  | ,'    |   :    | ---'    ;  |,'     \n"
           "            `--''       \\   \\  /          '--'       \n"
           "                         `----'                      \n"
           "                                                     ");
}


static int exit() {

    printf("");
    char ch = getchar();
    return (ch == 'y' || ch == 'Y') ? 1 : 0;
}

Panel panel = {printLogo, exit};
