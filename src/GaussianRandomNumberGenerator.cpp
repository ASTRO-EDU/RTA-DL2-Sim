#include "GaussianRandomNumberGenerator.h"


void GaussianRandomNumberGenerator::initSeed() {

  unsigned seed = chrono::system_clock::now().time_since_epoch().count();

  generator.seed(seed);

}


double GaussianRandomNumberGenerator::getSample() {
  return gaussianDistribution(generator);
}
