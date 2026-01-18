#include <stdio.h>
#include <unistd.h>

int main() {
  int x = 42;
  pid_t pid = fork();

  if (pid == 0) {
    // child
    x = 100;
    printf("pid=%d, &x%p, x=%d\n", pid, &x, x);
  } else {
    // parent
    printf("pid=%d, &x%p, x=%d\n", pid, &x, x);
  }
  return 0;
}