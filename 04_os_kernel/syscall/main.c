#include <stddef.h>

void _start() {
  const char msg[] = "hello\n";

  long ret;
  asm volatile(
      "mov $1, %%rax\n"  // syscall number: SYS_write = 1
      "mov $1, %%rdi\n"  // fd = 1 (stdout)
      "mov %1, %%rsi\n"  // buf
      "mov %2, %%rdx\n"  // count
      "syscall\n"        // カーネルへ突入
      "mov %%rax, %0\n"  // 戻り値
      : "=r"(ret)
      : "r"(msg), "r"(sizeof(msg) - 1)
      : "rax", "rdi", "rsi", "rdx", "rcx", "r11", "memory");
}