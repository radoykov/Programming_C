#include <stdio.h>

int main()
{
    int a, b;

    printf("\na=");
    scanf("%d", &a);
    printf("\nb=");
    scanf("%d", &b);

    int sum = 1, i=2;
    while (a != 1 || b != 1)
    {
        if (a % i == 0 && b % i == 0)
        {
            sum *= i;
            a = a / i;
            b = b / i;
        }

        else if(a % i == 0)
        {
            sum *= i;
            a = a / i;
        } 

        else if (b % i == 0)
        {
            sum *= i;
            b = b / i;
        }

        else
        {
            i++;
            continue;
        }

        i=2;
    }
    printf("%d", sum);

    return 0;
}