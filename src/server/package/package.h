#ifndef SERVER_PACKAGE_H
#define SERVER_PACKAGE_H

#include "algorithm/algorithm.h"
#include "charset/charset.h"
#include "file/file.h"
#include "function/function.h"


typedef struct {

    ALGORITHM algorithm;
    Charset charset;
    File file;
    Function function;

} Package;

Package _package = {


};

#endif
