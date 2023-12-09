#include <stdio.h>
#include "mystrings.h"

int main(int argc, char **argv)
{
    if(argc!=2)
    {
        printf("Please provide a string!");
        return -1;
    }
    
    int a = strlength(argv[1]);

    printf("%d", a);

    return 0;
}