#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

void* worker(void* arg) {
  printf("[thread] pid=%d tid=%ld\n", getpid(), syscall(SYS_gettid));
  sleep(100);
}

int main() {
  pthread_t th;
  printf("[main] pid=%d tid=%ld\n", getpid(), syscall(SYS_gettid));

  pthread_create(&th, NULL, worker, NULL);

  sleep(100);
  pthread_join(th, NULL);
  return 0;
}
