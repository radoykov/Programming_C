#include <stdio.h>
#include "transformation.h"

int main() 
{
    struct transformation a;
    char arr[100];
    printf("\narr=");
    scanf("%s", &arr);
    a = transform(arr);

    printf("%ld\n", a.result);
    printf("%s", a.error);

    return 0;
}