#include <stdio.h>

#define SWAP(A, B, TYPE)\
    TYPE C;\
    C = A;\
    A = B;\
    B = C;

#define SORT(ARRAY, SIZE, TYPE, COMPARE)\
for (int i = 1; i < SIZE; i++)\
{\
    int change = 0;\
\
    for (int j = 0; j < SIZE - i; j++)\
    {\
        if (ARRAY[j] COMPARE ARRAY[j + 1])\
        {\
            SWAP(ARRAY[j], ARRAY[j+1], TYPE);\
            change = 1;\
        }\
    }\
    if (!change)\
        break;\
}

int main()
{
    char arr[5] = {'k', 'f', 'c', 'w', 'w'};
    SORT(arr, 5, char, <);

    for (int i = 0; i < 5; i++)
    {
        printf("%c\n", arr[i]);
    }

    return 0;
}