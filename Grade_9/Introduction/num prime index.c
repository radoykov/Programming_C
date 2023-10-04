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

int main()
{
    int n;

    do
    {
        printf("\nhow long array=");
        scanf("%d", &n);

    } while (n <= 0);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("\n%d = ", i + 1);
        scanf("%d", &arr[i]);
    }
    sortarr(arr, n);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i] * i;
    }
    printf("%d", sum);

    return 0;
}