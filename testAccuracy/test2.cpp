#include <random>

#include <cstdint>
#include <iostream>
using namespace std;

int main() {
  std::random_device rd{}; // use to seed the rng 
  std::mt19937 rng{rd()}; // rng


  for (float j = 1.0; j >= 0; j -= 0.1) {
    uint64_t fail = 0, success = 0;
    cout << "You're trying " << j << endl;
    std::bernoulli_distribution d(j);
    for (uint32_t i = 0; i < 100000; i++) {
      if (d(rng)) {
        success += 1;
      } else {
        fail += 1;
      }
    }
    cout << "real probability: " << (1.0 * success / (fail + success))
            << "\n---\n";
  }
}