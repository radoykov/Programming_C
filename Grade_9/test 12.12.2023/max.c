#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"

int main(int argc, char **argv)
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("max=%d", MAX(a, b));

    return 0;
}