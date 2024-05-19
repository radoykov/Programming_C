#ifndef DYN_ARR_H
#define DYN_ARR_H

typedef unsigned long ulong;

typedef struct book
{
    char name[30];
    char author[30];
    char genre[30];
    int year;
    ulong ISBN;

} Book;

typedef Book DynArrType;
typedef unsigned int uint;

typedef struct {
  DynArrType * buffer;
  uint size;
  uint capacity;
} DynamicArray;

DynamicArray init(int initialCapacity);

void push(DynamicArray *arr, uint index, DynArrType value);
void pushFront(DynamicArray *arr, DynArrType value);
void pushBack(DynamicArray *arr, DynArrType value);

DynArrType getElement(DynamicArray *arr, uint index);
void setElement(DynamicArray *arr, uint index, DynArrType value);

DynArrType removeElement(DynamicArray * arr, uint index);
DynArrType popBack(DynamicArray *arr);
DynArrType popFront(DynamicArray *arr);

void release(DynamicArray * arr);
#endif