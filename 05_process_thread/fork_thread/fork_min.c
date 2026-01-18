#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (pid == 0) {
    // child
    printf("[child] pid=%d tid=%ld\n", getpid(), syscall(SYS_gettid));
  } else {
    // parent
    printf("[parent] pid=%d tid=%ld\n", getpid(), syscall(SYS_gettid));
  }

  sleep(1);
}