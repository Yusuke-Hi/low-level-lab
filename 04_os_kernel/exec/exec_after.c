#include <stdio.h>
#include <unistd.h>

int main() {
  int y = 100;
  printf("after exec: &y=%p, y=%d, pid=%d\n", &y, y, getpid());
  return 0;
}