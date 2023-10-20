#include <stdio.h>

void sortarr(int arr[], int len);
int isprime(int number);
int countdigits(int number);
int getdigitssumonprimeindexes(int arr[], int len);

void main()
{
    int arr[] = {3, 17, 22, 342, 1024, 2025, 19, 25, 35, 85};
    int len = 10;
    printf("%d", getdigitssumonprimeindexes(arr, len));
}

int getdigitssumonprimeindexes(int arr[], int len)
{
    int totalnumberscount = 0;

    sortarr(arr, len);

    for (int i = 0; i < len; i++)
    {
        if (isprime(i) == 1)
        {
            totalnumberscount += countdigits(arr[i]);
        }
    }

    return totalnumberscount;
}

void sortarr(int arr[], int len)
{
    int change;
    for (int i = 1; i < len; i++)
    {
        change = 0;
        for (int j = 0; j < len - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                change = 1;
                int g = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = g;
            }
        }
        if (!change)
            break;
    }
}

int isprime(int number)
{
    if (number < 2)
    {
        return 0;
    }

    int k = 2;
    while (number % k != 0)
    {
        k++;
    }

    if (number == k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int countdigits(int number)
{
    int count = 0;
    while (number != 0)
    {
        number /= 10;
        count++;
    }
    return count;
}
