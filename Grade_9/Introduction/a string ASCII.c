#include <stdio.h>

int main()
{
    char S1[20], c=S1[0];

    printf("\nS1=");
    gets(S1);

    int i = 0;
    while (S1[i] != '\0')
    {
        if (c < S1[i + 1])
            c = S1[i + 1];

        i++;
    }
    printf("\n%c", c);

    return 0;
}