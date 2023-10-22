#include <stdio.h>

#define SWAP(A, B, TYPE) TYPE C;\
C = A;\
A = B;\
B = C;

int main()
{
  char a = 'a';
  char b = 'b';
 
  SWAP(a, b, char);

  printf("%c - %c", a, b);

  return 0;
}
