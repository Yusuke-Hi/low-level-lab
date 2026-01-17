#include <chrono>
#include <cstdio>

volatile int sink;

void dep() {
  int x = 0;
  for (int i = 0; i < 100000000; ++i) {
    x = x + 1;  // 真の依存
  }
  sink = x;
}

void indep() {
  int a = 0, b = 0;
  for (int i = 0; i < 100000000; ++i) {
    ++a;
    ++b;  // 独立
  }
  sink = a + b;
}

int main() {
  auto s1 = std::chrono::high_resolution_clock::now();
  dep();
  auto e1 = std::chrono::high_resolution_clock::now();
  printf(
      "dep   Time: %ld\n",
      std::chrono::duration_cast<std::chrono::milliseconds>(e1 - s1).count());

  auto s2 = std::chrono::high_resolution_clock::now();
  indep();
  auto e2 = std::chrono::high_resolution_clock::now();
  printf(
      "indep Time: %ld\n",
      std::chrono::duration_cast<std::chrono::milliseconds>(e2 - s2).count());
}
