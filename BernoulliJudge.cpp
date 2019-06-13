#include "BernoulliJudge.h"
#include <stdexcept>
#include <cmath> 
#include <random>

//test
#include <iostream>

BernoulliJudge::BernoulliJudge(float probability) {
  if (probability > 1 || probability < 0) {
    throw std::logic_error("The probability must be 0 ~ 1!");
  }
  this->amountOfSeed = 0;
  this->setMode(probability);
  this->updateSeed();

  std::cout << this->mode << "," << this->material1 << "," << this->material2 << std::endl;
}

bool BernoulliJudge::rand() {
  if (this->amountOfSeed == 0) {
    this->updateSeed();
  }

  bool result = this->seed % 2;
  this->seed >= 1;
  this->amountOfSeed -= 1;
  return result;
}

void BernoulliJudge::setMode(float probability) {
  float table[] = {
    1, 0.9921875, 0.984375, 0.96875, 0.9375,
    0.875, 0.75, 0.625, 0.5625, 0.53125,
    0.515625, 0.5078125, 0.50390625, 0.5, 0.4375,
    0.375, 0.34375, 0.3125, 0.296875, 0.28125,
    0.2734375, 0.265625, 0.26171875, 0.2578125, 0.255859375,
    0.25390625, 0.25, 0.234375, 0.21875, 0.1796875,
    0.171875, 0.15234375, 0.1484375, 0.138671875, 0.13671875,
    0.1318359375, 0.130859375, 0.125, 0.12109375, 0.1171875,
    0.091796875, 0.08984375, 0.0771484375, 0.076171875, 0.06982421875,
    0.0693359375, 0.0625, 0.0615234375, 0.060546875, 0.04638671875,
    0.0458984375, 0.038818359375, 0.03125, 0.031005859375, 0.03076171875,
    0.0233154296875, 0.015625, 0.0078125
  };

  char probabilityId = 0;
  float lastDistent = 1;

  for (int i = 0; i < 58; i++) {
    if (std::abs(probability - table[i]) >= lastDistent) {
      continue;
    }
    lastDistent = std::abs(probability - table[i]);
    probabilityId = i;
  }
  uint16_t id = probabilityId;
  this->searchModeAndMaterial(id);
}

void BernoulliJudge::searchModeAndMaterial(uint16_t id) {
  uint modes [] = {
    0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1,
    0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1,
    0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0
  };

  uint16_t table1[] = {
    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 7
  };

  uint16_t table2[] = {
    0, 7, 6, 5, 4, 3, 1, 2, 3, 4, 5, 6, 7, 0, 2, 2, 2, 3, 4, 4,
    5, 5, 6, 6, 7, 7, 0, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 0, 4, 4,
    5, 5, 6, 6, 7, 7, 0, 5, 5, 6, 6, 7, 0, 6, 6, 7, 0, 0
  };

  this->mode = modes[id];
  this->material1 = table1[id];
  this->material2 = table2[id];
}

uint64_t BernoulliJudge::getDigitalBernoulliSeed(uint16_t exp) {
  std::random_device randSeed;

  uint64_t seed = 0xffffffffffffffff;
  for (uint16_t j = 0; j < exp; j++) {
    std::mt19937_64 mt_rand(randSeed());
    seed &= mt_rand();
  }
  return seed;
}

void BernoulliJudge::updateSeed() {
  uint64_t seed1 = this->getDigitalBernoulliSeed(this->material1);
  uint64_t seed2 = this->material2 ? this->getDigitalBernoulliSeed(this->material2) : 0;
  this->amountOfSeed = 64;

  if (this->mode) {
    this->seed = seed1 ^ seed2;
  } else {
    this->seed = seed1 | seed2;
  }
}