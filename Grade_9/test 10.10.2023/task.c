#include <stdio.h>

void sortarr(int arr[], int len);
void simp(int arr[], int len, int barr[], int log);
int midd(int barr[], int log);
int end(int arr[], int len);

void main()
{
    int arr[] = {3, 17, 22, 342, 1024, 2025, 19, 25, 35, 85};
    int len = 10, a;
    a = end(arr, len);
    printf("%d", a);
}

void sortarr(int arr[], int len)
{
    int change;
    for (int i = 1; i < len; i++)
    {
        change = 0;
        for (int j = 0; i < len - i; i++)
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

void simp(int arr[], int len, int barr[], int log)
{
    for (int i = 0; i < len; i++)
    {
        int j = 2;

        while (i != 0)
        {
            if (i % j != 0)
                j++;
            else if (i == j)
            {
                int k = 0;
                barr[k] = arr[i];
                log++;
                k++;
            }
            else
                i++;
        }
    }
}
int midd(int barr[], int log)
{
    int pr = 0;
    for (int i = log; log!=0; i--)
    {
        while (barr[i] != 0)
        {
            pr += barr[i] % 10;
            barr[i] /= 10;
            i++;
        }
        if(log!=0)midd(barr, log-1);
    }

    return pr;
}

int end(int arr[], int len)
{
    int barr[20], log = 0;

    sortarr(arr, len);
    simp(arr, len, barr, log);
    int ho = midd(barr, log);
    return 0;
}