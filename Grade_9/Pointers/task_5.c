#include <stdio.h>

int compareasc(const void *const p1, const void *const p2)
{
    if (*(int *)p1 > *(int *)p2)
    {
        return 1;
    }
    else if (*(int *)p1 < *(int *)p2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int comparedesc(const void *const p1, const void *const p2)
{
    if (*(int *)p1 > *(int *)p2)
    {
        return -1;
    }
    else if (*(int *)p1 < *(int *)p2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void bubblesort(int arr[], int arrlen, int(compare)(const void *const, const void *const), void(swapelements)(void *, void *))
{
    for (int j = 1; j < arrlen; j++)
    {
        int change = 0;
        for (int k = 0; k < arrlen - j; k++)
        {
            if (compare(&arr[k], &arr[k + 1]) == 1)
            {
                change = 1;
                swapelements(&arr[k], &arr[k + 1]);
            }
        }
        if (!change)
            break;
    }
}

void swapelements(void *p1, void *p2)
{
    int g = *(int *)p1;
    *(int *)p1 = *(int *)p2;
    *(int *)p2 = g;
}

int main()
{
    int arr[5] = {8, 5, 10, -9, 1};

    // ascending order
    bubblesort(arr, 5, compareasc, swapelements);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // descending order
    bubblesort(arr, 5, comparedesc, swapelements);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}