#include <sys/syscall.h>
#include <unistd.h>

int main() { syscall(SYS_exit_group, 0); }
