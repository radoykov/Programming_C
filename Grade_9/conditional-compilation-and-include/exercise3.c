#include <stdio.h>

void sort(int arr[], int len);
void bs(int arr[], int len);
void ds(int arr[], int len);
void di(int arr[], int len);
void reversal(int arr[], int len);

int main()
{
    int arr[5] = {2, 7, 0, -9, 8};
    int len = 5;
    sort(arr, len);

    return 0;
}

void sort(int arr[], int len)
{
#ifdef _WIN32
    bs(arr, len);
#elif defined __LINUX__
    ds(arr, len);
#elif defined _MacOS_
    di(arr, len);
#else
reversal(arr, len);

#endif

    for (int i = 0; i < len; i++)
    {
        printf("\n%d", arr[i]);
    }
}

void bs(int arr[], int len)
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
}

void ds(int arr[], int len)
{
    int c, index;
    for (int i = 0; i < len; i++)
    {
        c = arr[i];
        index = i;

        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < c)
            {
                c = arr[j];
                index = j;
            }
        }
        arr[index] = arr[i];
        arr[i] = c;
    }
}

void di(int arr[], int len)
{
    int c;
    for (int i = 0; i < len; i++)
    {
        int j;
        c = arr[i];

        for (int j = i - 1; j >= 0; j++)
        {
            if (arr[j] > c)
            {
                arr[j + 1] = arr[j];
            }
            else
                break;
        }
        arr[j + 1] = c;
    }
}

void reversal(int arr[], int len)
{
    int c;
    for (int i = 0; i < len/2; i++)
    {
        c=arr[i];
        arr[i]=arr[len-1-i];
        arr[len-1-i]=c;
    }

}