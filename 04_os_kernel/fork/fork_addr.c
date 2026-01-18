#include <stdio.h>
#include <unistd.h>

int main() {
  int x = 42;
  pid_t pid = fork();

  printf("pid=%d, &x%p, x=%d\n", pid, &x, x);
  return 0;
}