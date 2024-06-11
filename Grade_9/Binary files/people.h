#ifndef PEOPLE_H
#define PEOPLE_H
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#define MAX_LENGHT_FOR_NAME 255

typedef enum
{
    Without = 0,
    Primary,
    Secondary,
    Higher

} Education;

typedef enum
{
    Unemployed = 0,
    Working

} WorkStatus;

typedef enum
{
    Merried = 0,
    Single

} MaritalStatus;

typedef struct
{
    ulong EGN;
    uchar nameLen;
    char name[MAX_LENGHT_FOR_NAME];
    ushort age;
    Education education;
    WorkStatus workStatus;
    MaritalStatus maritalStatus;
} Human;

typedef enum
{
    ShowAll = 1,
    Del,
    Add,
    Exit

} Commands;

typedef enum
{
    false = 0,
    true = 1
} Bool;

typedef struct readResult
{
    Bool succeeded;
    size_t size;

} ReadResult;




void printLegend();
void printHuman(Human *human);
uchar createflag(Education education, WorkStatus workStatus, MaritalStatus maritalStatus);
void fwriteHuman(Human *human, FILE *file);
ReadResult freadHuman(Human *human, FILE *file);
Education getEducation(uchar flag);
WorkStatus getWorkStatus(uchar flag);
MaritalStatus getMaritalStatus(uchar flag);


#endif