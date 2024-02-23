#include <stdio.h>
#define COLUMNS 4

void table(int arr[][COLUMNS], int rows)
{
    int ** arrptr = &arr;

    for (int k = 0; k < rows; k++)
    {
        for (int i = 0; i < COLUMNS; i++)
        {
            printf("%d ", **arrptr); 
            *arrptr = *arrptr + 1;
        }
        printf("\n");
    }
}

int main()
{
    int arr[3][COLUMNS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    table(arr, 3);

    return 0;
}