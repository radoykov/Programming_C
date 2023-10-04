#include <stdio.h>

void dac(int arr[], int n, int x)
{
    int l = 0, r = n - 1, k, ok = 0;
    for (int i = 0; i < n; i++)
    {
        k = (r + l) / 2;
        if (arr[k] == x)
        {
            ok = 1;
            break;
        }
        if (arr[k] > x)
            r = k - 1;
        if (arr[k] < x)
            l = k + 1;
        if (l > r)
            break;
    }
    if (ok)
        printf("\n%d",k);
    else
        printf("\n-1");
}
int main()
{
    int n, x;

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
    printf("\nx=");
    scanf("%d", &x);

    dac(arr, n, x);
    return 0;
}