#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int child_fn(void* arg) {
  printf("[child] pid=%d\n", getpid());
  return 0;
}

int main() {
  char stack[1024 * 1024];

  printf("[parent] pid=%d\n", getpid());

  int pid = clone(child_fn, stack + sizeof(stack), SIGCHLD, NULL);

  waitpid(pid, NULL, 0);
}
