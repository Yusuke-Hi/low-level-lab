#include <chrono>
#include <cstdio>

volatile long long sink;

void dependent() {
  long long x = 0;
  for (int i = 0; i < 200000000; ++i) {
    x = x + 1;  // 真の依存（RAW）
  }
  sink = x;
}

void independent() {
  long long a = 0, b = 0;
  for (int i = 0; i < 200000000; ++i) {
    a = a + 1;
    b = b + 1;  // 独立
  }
  sink = a + b;
}

int main() {
  auto s1 = std::chrono::high_resolution_clock::now();
  dependent();
  auto e1 = std::chrono::high_resolution_clock::now();

  auto s2 = std::chrono::high_resolution_clock::now();
  independent();
  auto e2 = std::chrono::high_resolution_clock::now();

  printf(
      "dependent   : %ld ms\n",
      std::chrono::duration_cast<std::chrono::milliseconds>(e1 - s1).count());
  printf(
      "independent : %ld ms\n",
      std::chrono::duration_cast<std::chrono::milliseconds>(e2 - s2).count());
}
