#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

int main()
{
    Employee *boss = createEmployee("Oliver", 3);

    Employee *mng1 = createEmployee("Vasko", 2);
    Employee *mng2 = createEmployee("Nikol", 0);
    Employee *mng3 = createEmployee("Alex Radoykov", 1);

    Employee *worker1 = createEmployee("Worker A", 0);
    Employee *worker2 = createEmployee("Worker B", 0);
    Employee *worker3 = createEmployee("Worker C", 0);

    mng1->teamMemebers[0] = worker1;
    mng1->teamMemebers[1] = worker2;

    mng3->teamMemebers[0] = worker3;

    boss->teamMemebers[0] = mng1;
    boss->teamMemebers[1] = mng2;
    boss->teamMemebers[2] = mng3;

    

    FILE *file = fopen("employee.bin", "wb");
    CHECK_FILE(file);

    writeTree(boss, file);
    freeTree(boss);

    fclose(file);

    return 0;
}