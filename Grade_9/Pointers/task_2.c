#include <stdio.h>
#include <string.h>

int main()
{
     char name[100];
     printf("a= ");
     fgets(name, 100, stdin);
     printf("%s", name);
     printf("new line");
     char *p = strchr(name, '\n');

     if (p != NULL)
     {
          *p = '\0';
     }

     printf("\n%s", name);
     printf("new line");

     return 0;
}
