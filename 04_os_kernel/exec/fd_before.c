#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  int fd = open("fd_test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
  printf("before exec: fd=%d\n", fd);

  execl("./fd_after", "fd_after", NULL);
}