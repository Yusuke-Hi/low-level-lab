#include <stdio.h>
#include <unistd.h>

int main() {
  int x = 42;
  pid_t pid = fork();

  if (pid == 0) {
    // child
    x = 100;
    printf("child: x = %d\n", x);
  } else {
    // parent
    printf("parent: x = %d\n", x);
  }
  return 0;
}