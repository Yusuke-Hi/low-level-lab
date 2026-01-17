#include <chrono>
#include <cstdio>

constexpr int N = 1e8;
int a[N];

int main() {
  auto s = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < N; ++i) {
    a[i] += 1;
  }
  auto e = std::chrono::high_resolution_clock::now();

  printf("time: %ld ms\n",
         std::chrono::duration_cast<std::chrono::milliseconds>(e - s).count());
}
