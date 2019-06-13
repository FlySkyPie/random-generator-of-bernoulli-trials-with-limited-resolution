#include "./../BernoulliJudge.h"

#include <iostream>
#include <cstdint>
using namespace std;

int main() {

  for (float j = 1.0; j >= 0; j -= 0.1) {
    BernoulliJudge judge(j);
    for (uint32_t i = 0; i < 100000; i++) {
      judge.rand();
    }
  }

  return 0;
}