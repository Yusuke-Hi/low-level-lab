#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main() {
  int fd = open("test.txt", O_WRONLY);
  if (fd < 0) {
    perror("open");
    return 1;
  }

  char buf[4096];
  memset(buf, 'A', sizeof(buf));
  long long count = 10485760;

  struct timespec start, end;
  clock_gettime(CLOCK_MONOTONIC, &start);

  while (count > 0) {
    write(fd, buf, sizeof(buf));
    fsync(fd);
    count -= sizeof(buf);
  }

  clock_gettime(CLOCK_MONOTONIC, &end);

  double sec =
      (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
  printf("write with fsync %lld bytes in %.6f sec\n", count, sec);

  close(fd);
}
