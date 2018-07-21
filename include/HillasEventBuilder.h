#include "EventDL2.h"
#include "GaussianRandomNumberGenerator.h"

#ifdef DEBUG
  #include <iostream>
  using std::cout;
  using std::endl;
#endif

using std::pair;

class HillasEventBuilder {

  public:

    HillasEventBuilder();
    ~HillasEventBuilder();

    void initGeneratorsSeed();

    EventDL2 * buildDL2Event(int eventId, int telescopeId);

  private:

    GaussianRandomNumberGenerator * sizeGRNG;
    GaussianRandomNumberGenerator * centroidXGRNG;
    GaussianRandomNumberGenerator * centroidYGRNG;
    GaussianRandomNumberGenerator * majorAxisGRNG;
    GaussianRandomNumberGenerator * lenghtGRNG;
    GaussianRandomNumberGenerator * widhtGRNG;


};
