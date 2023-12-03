#include <stdio.h>
#include <math.h>

int main()
{
    long arr[100];
    int len;
    printf("\nlen=");
    scanf("%d", &len);

    for (int i = 0; i < len; i++)
    {
        printf("%d=", i+1);
        scanf("%ld", &arr[i]);
    }

    for (int i = 0; i < len; i++)
    {
        arr[i] = pow(arr[i], 4);
    }
    for (int i = 0; i < len; i++)
    {
        printf("\n%ld", arr[i]);
    }

    return 0;
}