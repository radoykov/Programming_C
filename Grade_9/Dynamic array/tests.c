#include <stdio.h>
#include "dynarr.h"

void printDynamicArray(DynamicArray *arr)
{
  for (int i = 0; i < arr->size; i++)
  {
    printf("%f ", arr->buffer[i]);
  }
  printf("\n");
}

int main(void)
{

  printf("Executing tests \n");
  DynamicArray dynarr = init(2);
  printf("Initial capacity: %u\n", dynarr.capacity);
  printf("Initial size: %u\n", dynarr.size);

  pushBack(&dynarr, 10);
  pushBack(&dynarr, 15);
  pushBack(&dynarr, 20);
  printDynamicArray(&dynarr);

  push(&dynarr, 1, 7);
  printDynamicArray(&dynarr);

  pushFront(&dynarr, 11);
  printDynamicArray(&dynarr);

  DynArrType fourthElement = getElement(&dynarr, 3);
  printf("Fourth element: %lf\n", fourthElement);

  setElement(&dynarr, 10, 999);
  printDynamicArray(&dynarr);

  DynArrType thirdElement = removeElement(&dynarr, 2);
  printf("Third element: %lf\n", thirdElement);
  printDynamicArray(&dynarr);

  DynArrType firstElement = popFront(&dynarr);
  printf("First element: %lf\n", firstElement);
  printDynamicArray(&dynarr);

  DynArrType lastElement = popBack(&dynarr);
  printf("Last element: %lf\n", lastElement);
  printDynamicArray(&dynarr);

  printf("\nIndex: %d\n", getIndexOf(&dynarr, 10));
  printf("\nIndex: %d\n", getIndexOf(&dynarr, 20));
  printf("\nIndex: %d\n", getIndexOf(&dynarr, 1000));


  release(&dynarr);
  printf("Released capacity: %u\n", dynarr.capacity);
  printf("Released size: %u\n", dynarr.size);

  return 0;
}
