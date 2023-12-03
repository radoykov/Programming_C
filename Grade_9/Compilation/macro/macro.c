#include <stdio.h>
#define FUNCTION(A, B) (A + B)*(A + B)
int main() 
{
    int a, b;

    printf("\na=");
    scanf("%d", &a);
    printf("\nb=");
    scanf("%d", &b);

    printf("%d", FUNCTION(a, b));
    return 0;
}