#include <stdio.h>
#include "mystrings.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Please provide two strings!");
        return -1;
    }
    if (strlength(argv[1]) > 50)
    {
        printf("Error max 50 array1");
        return -1;
    }
    else if (strlength(argv[2]) > 50)
    {
        printf("Error max 50 array2");
        return -1;
    }

    strconcat(argv[1], argv[2]);
    printf("%s", argv[1]);

    return 0;
}