#include <stdio.h>
#include <string.h>

struct Student
{
    char name[20];
    int number;
    double avg;
};

int main()
{
    struct Student ivan;
    ivan.number = 10;
    ivan.avg = 5.5;
    strcpy(ivan.name, "Ivan");

    printf("\nnumber=%d", ivan.number);
    printf("\navg=%lf", ivan.avg);
    printf("\n%s", ivan.name);

        return 0;
}