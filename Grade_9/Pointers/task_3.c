#include <stdio.h>

void swap(void *a, void *b)
{
    int var = *(int *)a;
    *(int *)a =  *(int *)b;
     *(int *)b = var;
}

int main()
{
    int x1, x2;

    printf("\na=");
    scanf("%d", &x1);
    printf("\nb=");
    scanf("%d", &x2);


    swap(&x1, &x2);

    printf("\na=%d", x1);
    printf("\nb=%d", x2);

    return 0;
}