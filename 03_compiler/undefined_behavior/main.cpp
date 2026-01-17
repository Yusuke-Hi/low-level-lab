#include <cstdio>

int main() {
  int x;
  asm volatile("" : : "r"(x) : "memory");
  if (x == 0) {
    puts("zero");
  }
}
