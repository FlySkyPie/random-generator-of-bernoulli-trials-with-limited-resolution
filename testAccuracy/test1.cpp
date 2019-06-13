#include "./../BernoulliJudge.h"

#include <iostream>
#include <cstdint>
using namespace std;

int main() {

  for (float j = 1.0; j >= 0; j -= 0.1) {
    uint64_t fail = 0, success = 0;
    cout << "You're trying " << j << endl;
    BernoulliJudge judge(j);
    for (uint32_t i = 0; i < 100000; i++) {
      if (judge.rand()) {
        success += 1;
      } else {
        fail += 1;
      }
    }
    cout << "real probability: " << (1.0 * success / (fail + success))
            << "\n---\n";
  }

  return 0;
}