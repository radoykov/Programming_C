#include <stdio.h>
#include "counter.h"

int main()
{
    for(int i= 0; i< 10; i++)
    {
         printf("\nsum(%d) = %d", i, addoddtosum());
    }

    return 0;
}