#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
  int fd = open("test.txt", O_WRONLY);
  if (fd < 0) {
    perror("open");
    return 1;
  }

  char c = 'A';
  long long count = 10485760;

  struct timespec start, end;
  clock_gettime(CLOCK_MONOTONIC, &start);

  while (count--) {
    write(fd, &c, 1);
  }

  clock_gettime(CLOCK_MONOTONIC, &end);

  double sec =
      (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  printf("write %lld bytes in %.6f sec\n", count, sec);

  close(fd);
}
