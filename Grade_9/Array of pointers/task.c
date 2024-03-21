#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 15

#define CHECK(arr)                           \
    if (arr == NULL)                         \
    {                                        \
        printf("Error allocating memory\n"); \
        exit(1);                             \
    }

char *readLine(void)
{
    char c;
    int size = 0;
    char *line = NULL;

    do
    {
        size++;
        c = getchar();

        line = (char *)realloc(line, size * sizeof(char));
        CHECK(line)

        line[size - 1] = c;

        if (size > MAX_SIZE)
        {
            printf("\nError too big name");
            exit(1);
        }

    } while (c != '\n');

    line[size - 1] = '\0';

    return line;
}

int main()
{
    int subjectsCount;
    do
    {
        printf("\nNumber of subjects = ");
        scanf("%d", &subjectsCount);
        getchar();

    } while (subjectsCount <= 0);

    char **subjects = (char **)calloc(subjectsCount, sizeof(char *));
    CHECK(subjects)

    for (int i = 0; i < subjectsCount; i++)
    {
        printf("\nsubjects(%d) = ", i + 1);
        subjects[i] = readLine();
    }

    int command;
    printf("\n1 for add student");
    printf("\n2 for show diary");
    printf("\n3 for exit");

    char **students = NULL;
    float **grades = NULL;
    int studentsCount = 0;

    while (1)
    {
        printf("\ncommand = ");
        scanf("%d", &command);
        getchar();

        switch (command)
        {
        case 1:
            studentsCount++;

            students = (char **)realloc(students, studentsCount * sizeof(char *));
            CHECK(students)

            printf("\nstudent(%d) name = ", studentsCount);
            students[studentsCount - 1] = readLine();

            grades = (float **)realloc(grades, studentsCount * sizeof(float *));
            CHECK(grades)

            grades[studentsCount - 1] = (float *)calloc(subjectsCount, sizeof(float));
            CHECK(grades[studentsCount - 1])

            for (int j = 0; j < subjectsCount; j++)
            {
                do
                {
                    printf("\ngrade for %s = ", subjects[j]);
                    scanf("%f", &grades[studentsCount - 1][j]);

                } while (grades[studentsCount - 1][j] < 2 || grades[studentsCount - 1][j] > 6);
            }

            break;
        case 2:
            printf("%15c", ' ');
            for (int i = 0; i < subjectsCount; i++)
            {
                printf("%15s", subjects[i]);
            }
            printf("\n");
            for (int i = 0; i < studentsCount; i++)
            {
                printf("%15s", students[i]);
                for (int j = 0; j < subjectsCount; j++)
                {
                    printf("%15.2f", grades[i][j]);
                }

                printf("\n");
            }

            break;

        case 3:
            for (int i = 0; i < subjectsCount; i++)
            {
                free(subjects[i]);
            }
            free(subjects);

            for (int i = 0; i < studentsCount; i++)
            {
                free(students[i]);
                free(grades[i]);
            }
            free(students);
            free(grades);

            printf("Finished program");
            exit(0);

            break;

        default:
            printf("\nYou have provided an invalid command");
            break;
        }
    }

    return 0;
}