#include <stdio.h>
#include <stdlib.h>
#define CHECK(arr)                          \
    if (arr == NULL)                        \
    {                                       \
        printf("\nError alocating memory"); \
        exit(1);                            \
    }

char *readline(void)
{
    char *var = NULL;
    char c;
    int i = 0;

    do
    {
        i++;
        c = getchar();
        var = (char *)realloc(var, i * sizeof(char));
        CHECK(var)

        var[i - 1] = c;

    } while (c != '\n');

    var[i - 1] = '\0';

    return var;
}

int main()
{
    int count = 0;
    do
    {
        printf("\nnames count = ");
        scanf("%d", &count);
        getchar();

    } while (count <= 0);

    char **names = (char **)calloc(count, sizeof(char *));
    CHECK(names)

    for (int i = 0; i < count; i++)
    {
        printf("\nstudent(%d)name = ", i + 1);
        names[i] = readline();
    }
    printf("\nInputed names are = ");
    for (int i = 0; i < count; i++)
    {
        /*
        for (char *ptr = names[i]; *ptr != '\0'; ptr++)
        {
            printf("%c", *ptr);
        }

        printf(" ");
        */
         printf("%s ", names[i]);
    }

    for (int i = 0; i < count; i++)
    {
        free(names[i]);
    }
    free(names);

    return 0;
}