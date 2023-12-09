#include <stdio.h>
#include "mystrings.h"

int main(int argc, char **argv)
{
   int a = strcompare(argv[1], argv[2]);

   printf("%d", a);
    
    return 0;
} 