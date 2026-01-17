#include "f.hpp"

int f(int* __restrict p, float* __restrict q) {
  int sum = 0;
  for (int i = 0; i < 100000000; i++) {
    *q = 1.0f;
    sum += *p;
  }
  return sum;
}
