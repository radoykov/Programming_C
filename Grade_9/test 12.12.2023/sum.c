#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"

int main(int argc, char **argv)
{
    int a = atoi(argv[1]);
    
    printf("sum=%d", sum(a));

}