#include "maths.h"

int fact(int num)
{
    int n = num;
    int sum = 1;
    for (int i = 0; i < n; i++)
    {
        sum = sum * num;
        num--;
    }
    return sum;
}