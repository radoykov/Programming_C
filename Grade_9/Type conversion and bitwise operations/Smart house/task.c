#include <stdio.h>
#include <string.h>

int main()
{
    unsigned char lights = 0;
    int var;

    printf("Menu:\n");
    printf("1) Switch lights\n");
    printf("2) Print state\n");
    printf("3) Exit\n");

    while (1)
    {
        printf("\nPlease select an option =");
        scanf("%d", &var);

        if (var == 1)
        {
            int lamp = 0;

            printf("\nWhich lamp = ");
            scanf("%d", &lamp);
            lamp--;

            if (lamp < 0 || lamp > 7)
            {
                printf("error");
            }
            int l = 0;
            l = 1 << lamp;

            if ((lights & l) == l)
            {
                lights = lights & (~l);
            }
            else
            {
                lights = lights | l;
            }
        }

        else if (var == 2)
        {
            printf("\nThe light is on in rooms: ");
            int k = 0;
            for (int i = 0; i < 8; i++)
            {
                if ((lights >> i) & 1 == 1) 
                {
                    printf("%d ", i + 1);
                    k=1;
                }
            }
            if(k == 0)printf("None");
            printf("\n");
        }

        else if (var == 3)
            return 0;

        else
        {
            printf("\nError invalid name of operation");
        }
    }

    return 0;
}