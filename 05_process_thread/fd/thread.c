#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int fd;

void* worker(void* arg) {
  printf("[thread] pid=%d fd=%d\n", getpid(), fd);
  write(fd, "thread\n", 7);
  // close(fd);
}

int main() {
  fd = open("test.txt", O_CREAT | O_WRONLY, 0644);

  pthread_t th;
  printf("[main] pid=%d fd=%d\n", getpid(), fd);

  pthread_create(&th, NULL, worker, NULL);
  pthread_join(th, NULL);

  write(fd, "main\n", 5);
  close(fd);
}
