#include <stdio.h>
#include "processes.h"

int main()
{
    int a;

    printf("\nCreate new prosess(1)");
    printf("\nOutput(2)");
    printf("\nStop(3)");
    printf("\nExit(4)");

    while (1)
    {
        printf("\nComand = ");
        scanf("%d", &a);

        if (a == 1)
        {
            if (processescount == 5)
            {
                printf("\nError! Max number of processes has been reached!. Delete a process if you want to create a new one.");
                continue;
            }

            char name[30];

            printf("Name = ");
            scanf("%s", &name);

            int id = createnewprocess(name);
            printf("\nNew process #%d created.", id);
        }

        else if (a == 2)
        {
            for (int i = 0; i < processescount; i++)
            {
                printf("\nID = #%d name = %s", processes[i].id, processes[i].name);
            }
        }
        else if (a == 3)
        {
            int id;

            printf("\nWhich ID = ");
            scanf("%d", &id);
            stopprocess(id);
        }
        else if (a == 4)
        {
            printf("\nFinished program");
            return 0;
        }
        else printf("Error invalid comand");
    }
    return 0;
}