#include <stdio.h>
#include <module/init/init.h>
#include "include/define/rescode.h"



int main(void) {

    if(RES_OK != init_startup_success() ){

        return 1;
    }



    return 0;
}