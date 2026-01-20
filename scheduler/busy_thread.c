#include <pthread.h>
#include <unistd.h>

void* worker(void* arg) {
  while (1) {
    sleep(1);
  }
}

int main() {
  pthread_t th;
  pthread_create(&th, NULL, worker, NULL);
  while (1) {
  }
}
