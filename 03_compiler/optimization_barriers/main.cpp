volatile int global;

int main() {
  global = 1;

  // asm volatile("" ::: "memory");

  return global;
}