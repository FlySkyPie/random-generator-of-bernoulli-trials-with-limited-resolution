#ifndef FLYSKYPIE_BERNOULLIJUDGE_H
#define FLYSKYPIE_BERNOULLIJUDGE_H
#include <cstdint>

class BernoulliJudge {
public:
  BernoulliJudge(float probability);

  bool rand();
private:
  bool mode;
  uint16_t material1;
  uint16_t material2;
  uint16_t amountOfSeed;
  uint64_t seed;
  
  uint64_t getDigitalBernoulliSeed(uint16_t exp);
  void setMode(float probability);
  void searchModeAndMaterial(uint16_t id);
  void updateSeed();


};


#endif