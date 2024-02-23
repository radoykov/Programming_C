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
int main()
{
    char arr[] = "ivan";

    int len = strlenght(arr);

    printf("len=%d", len);
    

    return 0;
}