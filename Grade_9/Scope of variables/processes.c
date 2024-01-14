#include <string.h>
#include "processes.h"

struct Process processes[MAX_PROSESS_COUNT];
int processescount = 0;

static int maxid = 0;
static int nextprocessid(void)
{
    if (processescount == MAX_PROSESS_COUNT)
    {
        return 0;
    }
    maxid++;
    return maxid;
}

int createnewprocess(char name[])
{
    int id = nextprocessid();

    if (id == 0)
        return 0;

    struct Process newproces;
    strcpy(newproces.name, name);
    newproces.id = id;

    processes[processescount] = newproces;
    processescount++;

    return newproces.id;
}

void stopprocess(int id)
{
    for (int i = 0; i < processescount; i++)
    {
        if (processes[i].id == id)
        {
            for (int k = i; k < processescount - 1; k++)
            {
                processes[k] = processes[k + 1];
            }
            processescount--;
            break;
        }
    }
}