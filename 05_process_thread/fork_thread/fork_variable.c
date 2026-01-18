#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int x = 0;

int main() {
  pid_t pid = fork();
  if (pid == 0) {
    // child
    x++;
    printf("[child] pid=%d x=%d\n", getpid(), x);
  } else {
    // parent
    sleep(1);
    printf("[parent] pid=%d x=%d\n", getpid(), x);
  }
}