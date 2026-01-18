#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int x = 0;

void* worker(void* arg) {
  x++;
  printf("[thread] pid=%d x=%d\n", getpid(), x);
  return NULL;
}

int main() {
  pthread_t th;

  printf("[main] pid=%d x=%d\n", getpid(), x);
  pthread_create(&th, NULL, worker, NULL);
  pthread_join(th, NULL);
  printf("[main] pid=%d x=%d\n", getpid(), x);
}