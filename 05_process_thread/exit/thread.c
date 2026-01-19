#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>

void* worker(void* arg) {
  sleep(1);
  printf("[thread] poid=%d tid=%ld before exit()\n", getpid(),
         syscall(SYS_gettid));

  // exit(0);
  pthread_exit(NULL);
}

int main() {
  pthread_t th;

  printf("[main] pid=%d tid=%ld\n", getpid(), syscall(SYS_gettid));
  pthread_create(&th, NULL, worker, NULL);

  sleep(5);
  printf("[main] still alive?\n");

  pthread_join(th, NULL);
}