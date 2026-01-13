#include <chrono>
#include <cstdio>
#include <vector>

using Clock = std::chrono::high_resolution_clock;

int main() {
  const size_t sizes[] = {
      4 * 1024,         // 4KB  (L1)
      64 * 1024,        // 64KB (L2?)
      512 * 1024,       // 512KB
      4 * 1024 * 1024,  // 4MB  (L3)
      64 * 1024 * 1024  // 64MB (RAM)
  };

  for (size_t size : sizes) {
    std::vector<int> v(size / sizeof(int), 1);

    auto start = Clock::now();
    long long sum = 0;
    for (int repeat = 0; repeat < 100; repeat++) {
      for (size_t i = 0; i < v.size(); i++) {
        sum += v[i];
      }
    }
    auto end = Clock::now();

    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
                  .count();
    printf("size=%7zu KB, time=%ld ns\n", size / 1024, ns);
  }

  getchar();
}
