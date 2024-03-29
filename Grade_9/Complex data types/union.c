#include <stdio.h>
#define Lenght 10
typedef union Union
{
    long odd;
    short even;
} Union;

int main()
{
    Union arr[Lenght];

    for (int i = 0; i <= Lenght; i++)
    {
        if (i % 2 == 0)
        {
            arr[i].even = i;
        }
        else
        {
            arr[i].odd = i;
        }
    }

    for (int i = 0; i <= Lenght; i++)
    {
        printf("\nodd(%d) = %ld", i, arr[i].odd);
    }

    for (int i = 0; i < Lenght; i++)
    {
        printf("\neven(%d) = %hu", i , arr[i].even);
    }

    return 0;
}