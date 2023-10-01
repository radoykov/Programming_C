#include <stdio.h>

void sortarr(int arr[], int lon)
{
    for (int i = 1; i < lon; i++)
    {
        int change = 0;

        for (int j = 0; j < lon - i; j++)
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
}

int prime(int arr[], int lon)
{
    int sum = 0;
    for (int i = 0; i < lon; i++)
    {
        if (arr[i] == 1)
        {
            sum += 1;
            continue;
        }

        int k = 2;
        while (arr[i] % k != 0)
            k++;

        if (arr[i] == k)
            sum += arr[i];
    }

    return sum;
}

int main()
{
    int arr[] = {1, 7, 10, 15, 16, 13, 23, 30};
    int longarr = 8;
    sortarr(arr, longarr);
    int sum = prime(arr, longarr);
    printf("%d", sum);

    return 0;
}