#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "transformation.h"

struct transformation transform(char test[])
{
    int ok = 1;
    for (int i = 0; test[i] != '\0'; i++)
    {
        if (test[0] != '-' && test[0] != '+' && (test[0] < '1' || test[0] > '9'))
        {
            ok = 0;
            break;
        }

        if (i > 0 && (test[i] < '0' || test[i] > '9'))
        {
            ok = 0;
            break;
        }
    }
    struct transformation temp;

    if (ok)
    {
        temp.result = strtol(test, 0, 10);
        temp.error[0] = '\0';
    }
    else
    {
        temp.result = 0;
        strcpy(temp.error, "Invalid input string");
    }
    return temp;
}