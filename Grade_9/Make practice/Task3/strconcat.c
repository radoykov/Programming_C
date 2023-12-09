#include <stdio.h>
#include "mystrings.h"

int main(int argc, char **argv)
{
    strconcat(argv[1], argv[2]);
    printf("%s", argv[1]);

    return 0;
} 