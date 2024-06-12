#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef unsigned int uint;
#define MAX_NAME_LENGHT 100
#define CHECK_MEMORY(arr)                    \
    if (arr == NULL)                         \
    {                                        \
        printf("\nError alocating memory."); \
        exit(1);                             \
    }

#define CHECK_FILE(file)                \
    if (file == NULL)                   \
    {                                   \
        printf("\nCan not open file."); \
        exit(1);                        \
    }

typedef struct employee
{
    char name[MAX_NAME_LENGHT];
    uint teamSize;
    struct employee **teamMemebers;

} Employee;

void printTree(Employee *boss);
void printTreeRecursive(Employee *boss);

Employee *createEmployee(char *name, uint teamSize);
void writeEmployee(Employee *employee, FILE *file);
void writeTree(Employee *boss, FILE *file);
Employee *readEmployee(FILE *file);
Employee *readTree(FILE *file);
void freeEmployee(Employee * employee);
void freeTree(Employee *boss);


#endif