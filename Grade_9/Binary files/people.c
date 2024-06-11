#include "people.h"
#include <string.h>

const char *educationNames[] = {"Without" , "Primary", "Secondary", "Higher"};
const char *workStatusNames[] = {"Unemployed" , "Working"};
const char *maritalStatusNames[] = {"Merried" , "Single"};

void printHuman(Human* human)
{
    printf("\nEGN: %lu ", human->EGN);
    printf("\nName: %s", human->name);
    printf("\nAge: %hu", human->age);
    printf("\nEducation: %s",  educationNames[human->education]);
    printf("\nWork status: %s",  workStatusNames[human->workStatus]);
    printf("\nMarital status: %s",  maritalStatusNames[human->maritalStatus]);
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

void fwriteHuman(Human *human, FILE *file)
{
    fwrite(&human->EGN, sizeof(ulong), 1, file);
    fwrite(&human->nameLen, sizeof(uchar), 1, file);
    fwrite(&human->name, sizeof(char) * human->nameLen, 1, file);
    fwrite(&human->age, sizeof(ushort), 1, file);
    uchar flag = createflag(human->education, human->workStatus, human->maritalStatus);
    fwrite(&flag, sizeof(uchar), 1, file);
}

ReadResult freadHuman(Human *human, FILE *file)
{
    ReadResult result = {
        .size = 0,
        .succeeded = false
    };

    uchar count = 0;
    count += fread(&human->EGN, sizeof(ulong), 1, file);
    count += fread(&human->nameLen, sizeof(uchar), 1, file);
    memset(&human->name, 0, MAX_LENGHT_FOR_NAME);
    count += fread(&human->name, sizeof(char) * human->nameLen, 1, file);
    count += fread(&human->age, sizeof(ushort), 1, file);
    uchar flag;
    count += fread(&flag, sizeof(uchar), 1, file);
    human->education = getEducation(flag);
    human->workStatus = getWorkStatus(flag);
    human->maritalStatus = getMaritalStatus(flag);

    if(count == 5)
    {
        result.succeeded = true;
        result.size = sizeof(ulong) + 2 * sizeof(uchar) + sizeof(char) * human->nameLen + sizeof(ushort);
    }
    return result;
}

Education getEducation(uchar flag)
{
    if ((flag & 1) == 1)
        return Without;
    if ((flag & 2) == 2)
        return Primary;
    if ((flag & 4) == 4)
        return Secondary;
    if ((flag & 8) == 8)
        return Higher;
}

WorkStatus getWorkStatus(uchar flag)
{
    if ((flag & 16) == 16)
        return Unemployed;
    if ((flag & 32) == 32)
        return Working;
}

MaritalStatus getMaritalStatus(uchar flag)
{
    if ((flag & 64) == 64)
        return Merried;
    if ((flag & 128) == 128)
        return Single;
}