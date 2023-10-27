#ifndef _SCHOOLCLASS_H
#define _SCHOOLCLASS_H

#include "person.h"

struct SchoolClass {
  struct Person students[26];
  char letter;
  int number;
  struct Person classleader;
};

#endif