#include <random>

int main() {
  std::random_device rd{}; // use to seed the rng 
  std::mt19937 rng{rd()}; // rng


  for (float j = 1.0; j >= 0; j -= 0.1) {
    std::bernoulli_distribution d(j);
    for (uint32_t i = 0; i < 100000; i++) {
      d(rng);
    }
  }
}