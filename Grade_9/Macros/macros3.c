#include <stdio.h>

#define DEBUG(A) printf("Name:%s\n", #A);\
 printf("Value:%d\n", A);\
 printf("File:%s\n", __FILE__);\
 printf("Line:%d\n", __LINE__);

int main(void)
{

    int varname = 70;
    DEBUG(varname);

    return 0;
}