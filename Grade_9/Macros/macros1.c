#include <stdio.h>

#define SIZE 5

int main(void)
{
  int arry[SIZE]={2, 7, 8, 9, 12};

  for (int i = 0; i < SIZE; i++)
  {
    printf("%d\n", arry[i]);
  }
  
  return 0;
}