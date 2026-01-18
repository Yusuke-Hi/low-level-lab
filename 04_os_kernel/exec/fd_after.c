#include <string.h>
#include <unistd.h>

int main() {
  const char* msg = "hello after exec\n";
  write(3, msg, strlen(msg));
}