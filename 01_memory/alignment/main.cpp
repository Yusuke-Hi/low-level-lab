#include <cstddef>
#include <cstdio>

struct A {
  char c;
  int i;
};

struct B {
  int i;
  char c;
};

struct C {
  alignas(16) char c;
  int i;
};

int main() {
  printf("sizeof(A) = %zu\n", sizeof(A));
  printf("sizeof(B) = %zu\n", sizeof(B));
  printf("sizeof(C) = %zu\n", sizeof(C));

  A a;
  B b;
  C c;

  printf("&a.c = %p\n", &a.c);
  printf("&a.i = %p\n", &a.i);

  printf("&b.i = %p\n", &b.i);
  printf("&b.c = %p\n", &b.c);

  printf("&c.c = %p\n", &c.c);
  printf("&c.i = %p\n", &c.i);

  printf("offsetof(A,c) = %zu\n", offsetof(A, c));
  printf("offsetof(A,i) = %zu\n", offsetof(A, i));

  getchar();
}