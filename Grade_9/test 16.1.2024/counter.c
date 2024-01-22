#include "counter.h"
long sum = 0;

static int nextodd(void)
{
    static int var = -1;

    var+= 2;

    return var;
}

int addoddtosum()
{
    sum += nextodd();
    return sum;
}