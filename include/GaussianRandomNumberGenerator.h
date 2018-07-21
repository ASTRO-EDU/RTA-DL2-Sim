#include "random"
#include <chrono>

#ifdef DEBUG
  #include <iostream>
  using std::cout;
  using std::endl;
#endif

using std::normal_distribution;
using std::default_random_engine;
using namespace std; //  altrimenti non trova chrono.. -.-


class GaussianRandomNumberGenerator {

  public:

    GaussianRandomNumberGenerator(float mean, float stddev) : gaussianDistribution(mean, stddev), generator(0) { initSeed(); }

    void initSeed();

    double getSample();

  private:

    normal_distribution<double> gaussianDistribution;

    default_random_engine generator;
};
