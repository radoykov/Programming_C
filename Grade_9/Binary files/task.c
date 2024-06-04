#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <fileapi.h>
#include "people.h"
#include "fileUtil.h"

void printLegend();
void printHuman(Human human);
uchar createflag(Education education, WorkStatus workStatus, MaritalStatus maritalStatus);

int main()
{
    char fileName[30];
    printf("\nFile name: ");
    scanf("%s", &fileName);

    FILE *file = fopen(fileName, "ab+");
    check(file);

    fclose(file);

    int command;

    while (true)
    {
        printLegend();
        printf("\nCommand: ");
        scanf("%d", &command);

        switch (command)
        {
        case ShowAll:

            FILE *file = fopen(fileName, "rb");
            check(file);

            Human human;
            size_t result = 0;

            uint change = 0;
            while (true)
            {
                result = fread(&human, sizeof(Human), 1, file);
                if (change == 0 && result != 1)
                {
                    printf("\nThere have not humans properties");
                    break;
                }
                if (result != 1)
                    break;
                printHuman(human);
                change = 1;
            }
            fclose(file);
            break;
        case Del:
            ulong EGNToDel;
            printf("\nInput EGN: ");
            scanf("%lu", &EGNToDel);

            FILE *file3 = fopen(fileName, "rb+");
            rewind(file3);

            Human current;

            uint found = 0, humanCount=0;
            while (true)
            {
                result = fread(&current, sizeof(Human), 1, file3);
                if (result != 1)
                    break;


                if (current.EGN == EGNToDel)
                {
                    Human next;
                    while (true)
                    {
                        result = fread(&next, sizeof(Human), 1, file3);
                        if (result != 1)
                            break;
                        fseek(file3, -2 * (long)sizeof(Human), SEEK_CUR);
                        fwrite(&next, sizeof(Human), 1, file3);
                        fseek(file3, sizeof(Human), SEEK_CUR);
                        humanCount++;
                    }
                    found = 1;
                    break;
                }
                humanCount++;
            }

            _chsize_s(_fileno(file3), humanCount * sizeof(Human));
            if (found == 0)
                printf("\nEGN not found.");
            fclose(file3);
            break;
        case Add:
            Human humanToAdd;
            printf("\nEGN: ");
            scanf("%lu", &humanToAdd.EGN);
            getchar();
            printf("\nName: ");
            fgets(humanToAdd.name, MAX_LENGHT_FOR_NAME, stdin);
            char *p = strchr(humanToAdd.name, '\n');
            if (p != NULL)
            {
                *p = '\0';
            }
            printf("\nAge: ");
            scanf("%hu", &humanToAdd.age);
            printf("\nEducation(Without = 0,Primary = 1,Secondary = 2,Higher = 3): ");
            Education education;
            scanf("%d", &education);
            printf("\nWork status(Unemployed = 0, Working = 1): ");
            WorkStatus workStatus;
            scanf("%d", &workStatus);
            printf("\nMarital status(Merried = 0, Single = 1): ");
            MaritalStatus maritalStatus;
            scanf("%d", &maritalStatus);

            humanToAdd.flag = createflag(education, workStatus, maritalStatus);

            FILE *file2 = fopen(fileName, "ab");
            check(file2);

            fwrite(&humanToAdd, sizeof(Human), 1, file2);

            fclose(file2);
            break;
        case Exit:
            printf("\nProgram have finished.");
            exit(0);
            break;

        default:
            printf("\nYou have inputed a wrong command. Plese try again.");
            break;
        }
    }

    return 0;
}

void printHuman(Human human)
{
    printf("\nEGN: %lu ", human.EGN);
    printf("\nName: %s", human.name);
    printf("\nAge: %hu", human.age);
    // printf("\nflag: %d", human.flag);

    uchar var;
    var = 1;
    if ((human.flag & var) == var)
        printf("\nEducation: Without");
    var *= 2;
    if ((human.flag & var) == var)
        printf("\nEducation: Primary");
    var *= 2;
    if ((human.flag & var) == var)
        printf("\nEducation: Secondary");
    var *= 2;
    if ((human.flag & var) == var)
        printf("\nEducation: Higher");
    var *= 2;
    if ((human.flag & var) == var)
        printf("\nWork status: Unemployed");
    var *= 2;
    if ((human.flag & var) == var)
        printf("\nWork status: Working");
    var *= 2;
    if ((human.flag & var) == var)
        printf("\nMarital status: Merried");
    var *= 2;
    if ((human.flag & var) == var)
        printf("\nMarital status: Single");

    printf("\n");
}

void printLegend()
{
    printf("\nView all humans -> 1");
    printf("\nDeleta a human -> 2");
    printf("\nAdd new human -> 3");
    printf("\nExit -> 4");
}

uchar createflag(Education education, WorkStatus workStatus, MaritalStatus maritalStatus)
{
    uchar flag = 0;

    flag = flag | (1 << education);
    flag = flag | (1 << workStatus + 4);
    flag = flag | (1 << maritalStatus + 6);

    return flag;
}
