#include <stdio.h>
#define ARRAY_SIZE 8
#define PARAMETARS \
for(int i = 0; i < ARRAY_SIZE; i++) \
{\
    int a=1;\
    for(int k=0; k<i; k++) a*=2;\
    arr[i]=a;\
}




int main()
{
    #if defined ARRAY_SIZE && ARRAY_SIZE <= 10 && ARRAY_SIZE >= 1
    int arr[ARRAY_SIZE];
    PARAMETARS
    for (int i = 0; i < ARRAY_SIZE; i++)
    printf("\n%d", arr[i]);
    return 0;
    #else
    printf("\nError");
    #endif
}