#include <unistd.h>

int main() {
  char* p = (char*)0x12345678;
  write(1, p, 6);
  return 0;
}
