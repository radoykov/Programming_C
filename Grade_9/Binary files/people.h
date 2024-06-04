#ifndef PEOPLE_H
#define PEOPLE_H

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
    char name[MAX_LENGHT_FOR_NAME];
    ushort age;
    uchar flag;

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

#endif