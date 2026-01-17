#include <stdio.h>

#include "f.hpp"

int main() {
  int x = 0;
  printf("%d\n", f(&x, (float*)&x));
}