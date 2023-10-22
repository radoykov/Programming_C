#include <stdio.h>

#define COMMAND(NAME, TYPE) TYPE ## _ ## NAME ## _ ## command
#define DEFINE_COMMAND(NAME, TYPE) void COMMAND(NAME,TYPE) ()

DEFINE_COMMAND(internal, start);
DEFINE_COMMAND(external, quit);

int main()
{
  COMMAND(internal, start)();
  COMMAND(external, quit)();


  return 0;
}

DEFINE_COMMAND(internal, start)
{
  printf("hello");
}

DEFINE_COMMAND(external, quit)
{
  printf("world");
}
