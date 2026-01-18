#include <stdio.h>
#include <unistd.h>

int main() {
  int x = 42;
  printf("before exec: &x=%p, x=%d, pid=%d\n", &x, x, getpid());

  execl("./exec_after", "exec_after", NULL);

  printf("after exec\n");
  return 0;
}