#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

int main()
{
    FILE *file = fopen("employee.bin", "rb");
    CHECK_FILE(file);

    Employee * boss = readTree(file);
    printTree(boss);
    //printTreeRecursive(boss);
    freeTree(boss);
    fclose(file);

    return 0;
}