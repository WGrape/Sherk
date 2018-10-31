#include <stdio.h>
#include <module/init/init.h>
#include "include/define/rescode.h"



int main(void) {

    if(RES_OK != init_startup_success() ){

        // 启动失败
        return 1;
    }



    return 0;
}