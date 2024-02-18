#include <stdio.h>

int main()
{
    double a, b;

    printf("\na=");
    scanf("%lf", &a);

    printf("\nb=");
    scanf("%lf", &b);

    double *p1 = &a;
    double *p2 = &b;

    printf("\nvalue=%.4lf  address=%p ", *p1, p1);
    printf("\nvalue=%.4lf  address=%p ", *p2, p2);

    return 0;
}
