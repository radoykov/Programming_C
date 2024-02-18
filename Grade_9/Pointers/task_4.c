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

int main()
{
    int a = 5, b = 6;

    printf("\ncompareasc = %d", compareasc(&a, &b));
    printf("\ncomparedesc = %d", comparedesc(&a, &b));

    return 0;
}