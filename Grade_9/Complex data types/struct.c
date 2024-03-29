#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSizeOfName 15

typedef struct Student
{
    char name[15];
    int number;
    double grade;
} StudentType;

enum Command
{
    Add = 1,
    Show,
    Exit
};

int main()
{
    enum Command command;
    int count = 0;

    printf("\n1 -> Add student");
    printf("\n2 -> Show students");
    printf("\n3 -> Exit");

    while (1)
    {
        printf("\nInput comand = ");
        scanf("%d", &command);

        switch (command)
        {
        case Add:

            StudentType * kid = (StudentType *)realloc((void *)kid, (count + 1) * sizeof(StudentType));

            do
            {
                printf("\nName = ");
                scanf("%s", kid[count].name);

            } while (strlen(kid[count].name) > MaxSizeOfName);

            printf("\nNumber = ");
            scanf("%d", &kid[count].number);

            do
            {
                printf("\nGrade = ");
                double x =-1;
                scanf("%lf", &kid[count].grade);
            } while (kid[count].grade < 2 || kid[count].grade > 6);

            count++;

            break;
        case Show:

            printf("Names\t");
            printf("Numbers\t");
            printf("Grades\t");
            printf("\n");

            for (int i = 0; i < count; i++)
            {
                printf("%s\t", kid[i].name);
                printf("%d\t", kid[i].number);
                printf("%lf\t", kid[i].grade);
                printf("\n");
            }

            break;
        case Exit:

            free(kid);

            printf("\nFinished program");
            exit(0);

            break;

        default:
            printf("\nYou have been inputed a wrong number");
            break;
        }
    }

    return 0;
}