#include <stdio.h>

#define OPER(X, Y) X > Y ? X : Y

int main()
{
    int a = 2;
    int b = 7;
    printf("%d", OPER(a, b));
    return 0;
}