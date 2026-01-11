#include <cstdio>
#include <cstdlib>

int global_var = 42;

int main() {
  int stack_var = 1;
  int* heap_var = (int*)std::malloc(sizeof(int));
  *heap_var = 2;

  printf("global_var: %p\n", &global_var);
  printf("stack_var: %p\n", &stack_var);
  printf("heap_var: %p\n", heap_var);

  std::getchar();
  std::free(heap_var);
}