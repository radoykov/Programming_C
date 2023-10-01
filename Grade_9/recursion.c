#include <stdio.h>

long rec(int num)
{
    int b = 0;

    if (num != 0)
    {
        b = rec(num / 2);
    }

    b = b * 10 + num % 2;

    return b;
}

int main()
{
    int num;

    printf("\nnumber=");
    scanf("%d", &num);

    long a;
    a = rec(num);

    printf("%ld", a);

    return 0;
}