#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <unistd.h>

int child_fn(void* arg) {
  printf("[clone] pid=%d tid=%ld\n", getpid(), syscall(SYS_gettid));
  sleep(5);
}

int main() {
  char stack[1024 * 1024];
  printf("[main] pid=%d tid=%ld\n", getpid(), syscall(SYS_gettid));

  int flags = CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_THREAD;
  clone(child_fn, stack + sizeof(stack), flags, NULL);

  sleep(5);
}
