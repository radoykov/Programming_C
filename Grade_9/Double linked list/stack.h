#ifndef STACK_H
#define STACK_H

#include "doublelinkedlist.h"

typedef ListType StackType;

typedef struct {
  List list;
} ListStack;

ListStack initStack();

void pushInStack(ListStack * stack, StackType value);

StackType popFromStack(ListStack * stack);

#endif 