#include <stdio.h>
#include "safeint.h"
#include "util.h"

int main(int argc, char **argv)
{
    struct SafeResult variable1, variable2;

    variable1 = safestrtoint(argv[1]);
    variable2 = safestrtoint(argv[2]);

    ERROR_CHECK(variable1.errorflag, MSG_INPUT_ERROR);
    ERROR_CHECK(variable2.errorflag, MSG_INPUT_ERROR);

    struct SafeResult res;
    res = safemultiply(variable1.value, variable2.value);

    ERROR_CHECK(res.errorflag, MSG_OVERFLOW);

    printf("%d", res.value);

    return 0;
}