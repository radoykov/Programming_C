#include "stack.h"

ListStack initStack() {
  List newList = init();
  ListStack stack = {
    .list = newList
  };
  return stack;
}

void pushInStack(ListStack * stack, StackType value) {
  pushFront(&(stack->list), value);
}

StackType popFromStack(ListStack * stack) {
  return popFront(&(stack->list));
}