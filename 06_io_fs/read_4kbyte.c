#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
  int fd = open("test.txt", O_RDONLY);
  if (fd < 0) {
    perror("open");
    return 1;
  }

  char buf[4096];
  long long count = 0;

  struct timespec start, end;
  clock_gettime(CLOCK_MONOTONIC, &start);

  while (read(fd, buf, sizeof(buf)) > 0) {
    count += sizeof(buf);
  }

  clock_gettime(CLOCK_MONOTONIC, &end);

  double sec =
      (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  printf("read %lld bytes in %.6f sec\n", count, sec);

  close(fd);
}