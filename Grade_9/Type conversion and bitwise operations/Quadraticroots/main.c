#include <stdio.h>
#include "quadraticroots.h"
#define PRINTF                             \
    if (variable.norealroots == 1)         \
    {                                      \
        printf("\nNO REAL ROOTS");         \
    }                                      \
    else                                   \
    {                                      \
        printf("\nx1 = %lf", variable.x1); \
        printf("\nx2 = %lf", variable.x2); \
    }

int main()
{
    int a1, b1, c1;

    printf("\n\na1=");
    scanf("%d", &a1);

    printf("\nb1=");
    scanf("%d", &b1);

    printf("\nc1=");
    scanf("%d", &c1);

    struct QuadraticRootsResult variable;

    variable = findroots((double)a1, (double)b1, (double)c1);

    PRINTF

    float a2, b2, c2;

    printf("\n\na2=");
    scanf("%f", &a2);

    printf("\nb2=");
    scanf("%f", &b2);

    printf("\nc2=");
    scanf("%f", &c2);

    variable = findroots((double)a2, (double)b2, (double)c2);

    PRINTF

    double a3, b3, c3;

    printf("\n\na3=");
    scanf("%lf", &a3);

    printf("\nb3=");
    scanf("%lf", &b3);

    printf("\nc3=");
    scanf("%lf", &c3);

    variable = findroots(a3, b3, c3);

    PRINTF

    return 0;
}
