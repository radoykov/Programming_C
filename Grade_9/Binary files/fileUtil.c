#include <stdio.h>
#include <stdlib.h>
#include "fileUtil.h"

void check(FILE *file)
{
    if (file == NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }
}
