#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid == 0) {
    exit(0);
  } else {
    sleep(1);
    printf("parent alive\n");
  }
}