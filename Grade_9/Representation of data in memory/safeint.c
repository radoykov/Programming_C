#include <stdio.h>
#include <limits.h>
#include "safeint.h"

struct SafeResult safeadd(int a, int b)
{
    struct SafeResult var;
    long long x, y, c;
    x = (long long)a;
    y = (long long)b;

    c = x + y;

    if (c > INT_MAX || c < INT_MIN)
        var.errorflag = 1;
    else
    {
        var.errorflag = 0;
        var.value = (int)c;
    }
    return var;
}

struct SafeResult safesubtract(int a, int b)
{
    struct SafeResult var;
    long long x, y, c;
    x = (long long)a;
    y = (long long)b;

    c = x - y;

    if (c > INT_MAX || c < INT_MIN)
        var.errorflag = 1;
    else
    {
        var.errorflag = 0;
        var.value = (int)c;
    }
    return var;
}

struct SafeResult safemultiply(int a, int b)
{
    struct SafeResult var;
    long long x, y, c;
    x = (long long)a;
    y = (long long)b;

    c = x * y;

    if (c > INT_MAX || c < INT_MIN)
        var.errorflag = 1;
    else
    {
        var.errorflag = 0;
        var.value = (int)c;
    }
    return var;
}

struct SafeResult safedivide(int a, int b)
{
    struct SafeResult var;
    long long x, y, c;
    x = (long long)a;
    y = (long long)b;

    if (y == 0)
    {
        var.errorflag = 1;
        return var;
    }
    c = x / y;

    if (c > INT_MAX || c < INT_MIN)
        var.errorflag = 1;
    else
    {
        var.errorflag = 0;
        var.value = (int)c;
    }
    return var;
}

struct SafeResult safestrtoint(char a[])
{
    struct SafeResult var;
    int i = 1, sign = 1, count = 10;
    var.value = 0;

    if (a[0] == '-')
        sign = -1;
    else if (a[0] == '+')
        sign = 1;
    else
        i = 0;
    
    while (a[i] != '\0')
    {
        a[i] = a[i] - '0';
        var = safemultiply(var.value, count);
        if (var.errorflag == 1)
            break;
        var = safeadd(var.value, a[i]);
        if (var.errorflag == 1)
            break;
        i++;
    }
    if(var.errorflag == 1) return var;
    var = safemultiply(var.value, sign);
    return var;
}