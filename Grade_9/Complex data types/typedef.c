#include <stdio.h>

typedef unsigned long long ull;
typedef ull(*callback)(ull, ull);

ull add(ull a, ull b)
{
    return a+b;
}

ull reduse(ull * arr, ull len, callback fptr, ull x)
{
    ull result = x;
    for (int i = 0; i < len; i++)
    {
            result = fptr(result, arr[i]);
    }

    return result;
}

int main()
{

    ull arr[3]={1, 2, 3};

    ull a;
    a = reduse(arr, 3, add, 0);

    printf("%lld", a);

    return 0;
}