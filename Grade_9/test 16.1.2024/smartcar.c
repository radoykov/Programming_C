#include <stdio.h>

int main()
{
    unsigned char lights = 237;

    printf("\n");

    for(int i = 1; i <= 8; i++)
    {
        if(lights & 1 == 1)
        {
            printf("work = %d\n", i);
        }
        lights = lights >> 1;
    }

    return 0;
}