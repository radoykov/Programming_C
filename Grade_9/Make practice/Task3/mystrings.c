#include <stdio.h>
#include "mystrings.h"

int strlength(char arr[])
{
    int i;

    for (i = 0; arr[i] != '\0'; i++);

    return i;
}

void strconcat(char arr[], char arr2[])
{
    int i, j;

    for (i = 0; arr[i] != '\0'; i++);

        for (j = 0; arr2[j] != '\0'; j++)
        {
            arr[i] = arr2[j];
            i++;
        }
    arr[i] = '\0';
}

int strcompare(char arr[], char arr2[])
{
    int i = 0;

    while (arr[i] != '\0')
    {
        if (arr2[i] == '\0')
            return 1;
        if (arr[i] != arr2[i])
        {
            if (arr[i] > arr2[i])
                return 1;
            else
                return -1;
        }
        i++;
    }
    if (arr2[i] != '\0')
        return -1;
}