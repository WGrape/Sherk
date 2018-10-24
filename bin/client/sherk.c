#include <stdio.h>
#include "../../src/launcher/client.launcher.c"


// 可执行文件 - 客户端程序


// 编译此 sherk.c 文件之后，会生成 sherk.exe 文件，这个就是客户端程序
// 之后，我们就可以使用 sherk 命令开启这个客户端程序

int main(int argc, char *argv[]){

	clientLaunch();

	return 0;
}