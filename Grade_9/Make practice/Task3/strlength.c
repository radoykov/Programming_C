#include <stdio.h>
#include "mystrings.h"

int main(int argc, char **argv)
{
    int a = strlength(argv[1]);

    printf("%d", a);

    return 0;
}