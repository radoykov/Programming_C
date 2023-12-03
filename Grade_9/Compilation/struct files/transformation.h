#ifndef _TRANSFORMATION_H
#define _TRANSFORMATION_H

struct transformation
{
    long result;
    char error[100];
};

struct transformation transform(char test[]);

#endif