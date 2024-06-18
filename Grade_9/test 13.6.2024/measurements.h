#ifndef MEASUREMENTS_H
#define MEASUREMENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct date
{
    int day;
    int month;
    int year;
} Date;

typedef struct sample
{
    float temperature;
    float chlorineAmount;
} Sample;

#define CHECK(file)                   \
    if (file == NULL)                 \
    {                                 \
        printf("\nError open file."); \
        exit(1);                      \
    }
#define TESTCOUNT 3

#endif