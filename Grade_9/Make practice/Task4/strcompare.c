#include <stdio.h>
#include "mystrings.h"

int main(int argc, char **argv)
{
    if(argc!=3)
    {
        printf("Please provide two strings!");
        return -1;
    }
    int a = strcompare(argv[1], argv[2]);

    printf("%d", a);

    return 0;
}