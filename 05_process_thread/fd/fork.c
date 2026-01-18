#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int fd = open("text.txt", O_CREAT | O_WRONLY, 0644);
  if (fd < 0) {
    perror("open");
    return 1;
  }

  pid_t pid = fork();
  if (pid == 0) {
    printf("[child] pid=%d fd=%d\n", getpid(), fd);
    write(fd, "child\n", 6);
    close(fd);
    printf("[child] closed fd\n");
  } else {
    sleep(1);
    write(fd, "parent\n", 7);
    close(fd);
    printf("[parent] wrote and closed fd\n");
  }
}