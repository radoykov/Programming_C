#include <stdio.h>
#include <stdlib.h>

#define CHECK(X)                             \
    if (X == NULL)                           \
    {                                        \
        printf("\nError memory allocation"); \
        exit(1);                             \
    }

int main()
{
    int grades;

    do
    {
        printf("\ngrades count =");
        scanf("%d", &grades);

    } while (grades <= 0);

    float *arr = (float *)malloc(sizeof(float) * grades);

    CHECK(arr)

    for (int i = 0; i < grades; i++)
    {
        do
        {
            printf("\n%d garde =", i + 1);
            scanf("%f", arr + i);

        } while (*(arr + i) < 2 || *(arr + i) > 6);
    }

    int command;

    printf("\n1 for AVG");
    printf("\n2 to add grades");
    printf("\n3 to delete the last grade");
    printf("\n4 to Exit");

    while (1)
    {
        printf("\nCommand = ");
        scanf("%d", &command);

        if (command == 1)
        {
            float avg = 0;
            for (int i = 0; i < grades; i++)
            {
                avg += *(arr + i);
            }
            avg /= grades;
            printf("\nAverage grades: %.3f", avg);
        }

        else if (command == 2)
        {
            grades++;
            arr = (float *)realloc(arr, grades * sizeof(float));
            CHECK(arr);

            do
            {
                printf("\nNew grade = ");
                scanf("%f", arr + grades - 1);

            } while (*(arr + grades - 1) < 2 || *(arr + grades - 1) > 6);
        }

        else if (command == 3)
        {
            if (grades != 1)
            {
                grades--;
                arr = (float *)realloc(arr, sizeof(float) * grades);
            }
            else
            {
                printf("\nYou have not enough grades to be deleted");
            }
        }

        else
        {
            free(arr);
            printf("\nFinished program");
            exit(0);
        }
    }

    return 0;
}