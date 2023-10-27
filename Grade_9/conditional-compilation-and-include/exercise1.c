#include <stdio.h>
#define DEBUG 

void sort(int arr[], int len);

int main()
{
    int arr[5] = {2, 7, 78, -9, 4};
    int len = 5;
    sort(arr, len);

    return 0;
}

void sort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int change = 0;

        for (int j = 0; j < len - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int g = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = g;
                change = 1;
            }
        }
        if (!change)
            break;
    }
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if(i%3==0)
        {
            sum+=arr[i];
            #ifdef DEBUG
            printf("\n%d", arr[i]);
            #endif
        }
    }
    printf("\nsum=%d", sum);

    #ifdef DEBUG
    for(int i=0; i<len; i++) printf("\n%d", arr[i]);
    #endif
    
}