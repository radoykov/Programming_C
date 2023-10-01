#include <stdio.h>

int main()
{
    int num;
    do
    {
        printf("number=");
        scanf("%d", &num);

    } while (num <= 0);

    int a, sum = 1;
    while (num > 0)
    {
        a = num % 10;
        num = num / 10;
        sum *= a;
    }
    printf("%d", sum);

    return 0;
}