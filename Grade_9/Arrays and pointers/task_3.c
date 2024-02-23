#include <stdio.h>

int strlenght(char * str)
{
    int len = 0;
    for(char * phr = str; *phr != '\0'; phr++)
    {
        len++;
    }
    return len;

}

void strhalf(char *arr, char **pp)
{
    int len = strlenght(arr);

    *pp = arr+(len/2);
}

int main()
{
    char arr[] = "ivanlybo";

    char *p = NULL;

    strhalf(arr, &p); 

    printf("%s", p);

    return 0;
}