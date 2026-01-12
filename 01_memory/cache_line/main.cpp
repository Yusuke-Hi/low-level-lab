#include <cstdint>
#include <cstdio>

struct X {
  int a;
  int b;
};

struct alignas(64) Y {
  int a;
  int b;
};

int main() {
  printf("sizeof(X) = %zu\n", sizeof(X));

  X Xarr[10];
  for (int i = 0; i < 10; i++) {
    printf("&Xarr[%d] = %p\n", i, &Xarr[i]);
  }

  printf("sizeof(Y) = %zu\n", sizeof(Y));
  Y Yarr[4];
  for (int i = 0; i < 4; i++) {
    printf("&Yarr[%d] = %p\n", i, &Yarr[i]);
  }

  getchar();
}