#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

Employee *createEmployee(char *name, uint teamSize)
{
    Employee *newEmployee = (Employee *)malloc(sizeof(Employee));
    CHECK_MEMORY(newEmployee);

    memset(newEmployee->name, 0, MAX_NAME_LENGHT);
    strcpy(newEmployee->name, name);

    newEmployee->teamSize = teamSize;

    if (teamSize == 0)
    {
        newEmployee->teamMemebers = NULL;
    }
    else
    {
        newEmployee->teamMemebers = (Employee **)malloc(teamSize * sizeof(Employee *));
        CHECK_MEMORY(newEmployee->teamMemebers);
    }

    return newEmployee;
}

void printTree(Employee *boss)
{
    printf("\n%s", boss->name);

    for (uint i = 0; i < boss->teamSize; i++)
    {
        Employee *manager = boss->teamMemebers[i];
        printf("\n  %s", manager->name);

        for (uint j = 0; j < manager->teamSize; j++)
        {
            Employee *worker = manager->teamMemebers[j];
            printf("\n    %s", worker->name);
        }
    }
}

void writeEmployee(Employee *employee, FILE *file)
{
    fwrite(employee->name, sizeof(char), MAX_NAME_LENGHT, file);
    fwrite(&employee->teamSize, sizeof(uint), 1, file);
}

Employee *readEmployee(FILE *file)
{
    char name[MAX_NAME_LENGHT];
    uint teamSize = 0;
    fread(name, sizeof(char), MAX_NAME_LENGHT, file);
    fread(&teamSize, sizeof(uint), 1, file);

    Employee *employee = createEmployee(name, teamSize);
    return employee;
}

void writeTree(Employee *boss, FILE *file)
{
    writeEmployee(boss, file);

    for (uint i = 0; i < boss->teamSize; i++)
    {
        Employee *manager = boss->teamMemebers[i];
        writeEmployee(manager, file);

        for (uint j = 0; j < manager->teamSize; j++)
        {
            Employee *worker = manager->teamMemebers[j];
            writeEmployee(worker, file);
        }
    }
}

Employee *readTree(FILE *file)
{
    Employee * boss = readEmployee(file);

    for (uint i = 0; i < boss->teamSize; i++)
    {
        Employee * manager = readEmployee(file);
        boss->teamMemebers[i] = manager;

        for (uint j = 0; j < manager->teamSize; j++)
        {
            Employee *worker = readEmployee(file);
            manager->teamMemebers[j] = worker;
        }
    }
    return boss;
}

void freeEmployee(Employee * employee){
    free(employee->teamMemebers);
    free(employee);
}

void freeTree(Employee *boss)
{
    for (uint i = 0; i < boss->teamSize; i++)
    {
        Employee *manager = boss->teamMemebers[i];
        for (uint j = 0; j < manager->teamSize; j++)
        {
            Employee *worker = manager->teamMemebers[j];
            freeEmployee(worker);
        }
        freeEmployee(manager);
    }
    freeEmployee(boss);
}

void printTreeRecursive(Employee *boss)
{
    printf("\n%s", boss->name);

    for (uint i = 0; i < boss->teamSize; i++)
    {
        printTreeRecursive(boss->teamMemebers[i]);
    }
}