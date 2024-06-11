#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "people.h"
#include "fileUtil.h"

#include <unistd.h>

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
            ReadResult result;
            uint change = 0;

            while (true)
            {
                result = freadHuman(&human, file);

                if (change == 0 && result.succeeded == false)
                {
                    printf("\nThe file contains no people!");
                    break;
                }
                if (result.succeeded == false)
                    break;
                printHuman(&human);
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
            ReadResult resultCurrent;
            uint found = 0;

            while (true)
            {
                resultCurrent = freadHuman(&current, file3);
                if (!resultCurrent.succeeded)
                    break;

                if (current.EGN == EGNToDel)
                {
                    Human next;
                    ReadResult resultNext;

                    while (true)
                    {
                        resultNext = freadHuman(&next, file3);
                        if (!resultNext.succeeded)
                            break;

                        fseek(file3, -1 * (long)(resultCurrent.size + resultNext.size), SEEK_CUR);
                        fwriteHuman(&next, file3);
                        fseek(file3, resultCurrent.size, SEEK_CUR);
                    }
                    
                    fseek(file3, -resultCurrent.size, SEEK_END);
                    _chsize_s(_fileno(file3), ftell(file3));

                    found = 1;
                    break;
                }
            }

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
                *p = '\0';

            humanToAdd.nameLen = strlen(humanToAdd.name);

            printf("\nAge: ");
            scanf("%hu", &humanToAdd.age);
            printf("\nEducation(Without = 0,Primary = 1,Secondary = 2,Higher = 3): ");
            scanf("%d", &humanToAdd.education);
            printf("\nWork status(Unemployed = 0, Working = 1): ");
            scanf("%d", &humanToAdd.workStatus);
            printf("\nMarital status(Merried = 0, Single = 1): ");
            scanf("%d", &humanToAdd.maritalStatus);

            FILE *file2 = fopen(fileName, "ab");
            check(file2);

            fwriteHuman(&humanToAdd, file2);

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