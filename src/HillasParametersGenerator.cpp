#include "HillasParametersGenerator.h"

using namespace std;

HillasParametersGenerator::HillasParametersGenerator()
{

}

double HillasParametersGenerator::randomNumberGenarator() {

  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  default_random_engine generator (seed);

  normal_distribution<double> distribution (5.0,2.0);

  return distribution(generator);;


  /* before modify
  double r = distribution(generator);

  if ( r < 2 ) {
    //cout << "r: " << r << endl;
    randomNumberGenarator();
  } else {
    //cout << "r: " << r << endl;
    return r;
  }
  */



}
