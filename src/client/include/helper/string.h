#ifndef CLIENT_INCLUDE_HELPER_STRING_H
#define CLIENT_INCLUDE_HELPER_STRING_H

char* strtolower(char *s){

    int i=0;
    while(s[i]!='\0'){

        if( s[i]>='A' && s[i]<='Z' ){

            s[i]+=32;
        }

        ++i;
    }

    return s;
}


#endif // CLIENT_INCLUDE_HELPER_STRING_H
