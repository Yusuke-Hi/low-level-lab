#include <chrono>
#include <cstdio>
#include <random>

constexpr int REP = 100000000;

volatile int sink;
volatile int data[REP];

void predictable() {
  int x = 0;
  for (int i = 0; i < REP; i++) {
    if (data[i] >= 0) {  // ほぼ常に true
      x++;
    }
  }
  sink = x;
}

void unpredictable() {
  int x = 0;
  for (int i = 0; i < REP; i++) {
    if (data[i] & 1) {  // ランダム
      x++;
    }
  }
  sink = x;
}

void branchless() {
  int x = 0;
  for (int i = 0; i < REP; i++) {
    x += (data[i] & 1);
  }
  sink = x;
}

int main() {
  for (int i = 0; i < REP; i++) {
    data[i] = rand();  // 実行時にしか分からない
  }

  auto s1 = std::chrono::high_resolution_clock::now();
  predictable();
  auto e1 = std::chrono::high_resolution_clock::now();

  auto s2 = std::chrono::high_resolution_clock::now();
  unpredictable();
  auto e2 = std::chrono::high_resolution_clock::now();

  auto s3 = std::chrono::high_resolution_clock::now();
  branchless();
  auto e3 = std::chrono::high_resolution_clock::now();

  printf(
      "predictable   : %ld ms\n",
      std::chrono::duration_cast<std::chrono::milliseconds>(e1 - s1).count());

  printf(
      "unpredictable : %ld ms\n",
      std::chrono::duration_cast<std::chrono::milliseconds>(e2 - s2).count());

  printf(
      "branchless : %ld ms\n",
      std::chrono::duration_cast<std::chrono::milliseconds>(e3 - s3).count());
}