#include <chrono>
#include <cstdio>
#include <thread>

struct Counter {
  alignas(64) int value;
};

Counter a;
Counter b;

void inc_a() {
  for (int i = 0; i < 100'000'000; i++) {
    a.value++;
  }
}

void inc_b() {
  for (int i = 0; i < 100'000'000; i++) {
    b.value++;
  }
}

int main() {
  auto start = std::chrono::high_resolution_clock::now();

  std::thread t1(inc_a);
  std::thread t2(inc_b);

  t1.join();
  t2.join();

  auto end = std::chrono::high_resolution_clock::now();
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                .count();
  printf("Time: %ld ms\n", ms);
}
