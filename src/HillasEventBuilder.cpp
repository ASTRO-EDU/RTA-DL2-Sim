#include "HillasEventBuilder.h"

HillasEventBuilder::HillasEventBuilder() {

  #ifdef DEBUG
    cout << "[HillasEventBuilder] Initialization.." << endl;
  #endif

  sizeGRNG = new GaussianRandomNumberGenerator(5.0,2.0);
  centroidXGRNG = new GaussianRandomNumberGenerator(5.0,2.0);
  centroidYGRNG = new GaussianRandomNumberGenerator(5.0,2.0);
  majorAxisGRNG = new GaussianRandomNumberGenerator(5.0,2.0);
  lenghtGRNG = new GaussianRandomNumberGenerator(5.0,2.0);
  widhtGRNG = new GaussianRandomNumberGenerator(5.0,2.0);

  initGeneratorsSeed();

}

HillasEventBuilder::~HillasEventBuilder() {

/*
  delete(sizeGRNG);
  delete(sizeGRNG);
  delete(centroidXGRNG);
  delete(centroidYGRNG);
  delete(majorAxisGRNG);
  delete(lenghtGRNG);
  delete(widhtGRNG);
  */

}


void HillasEventBuilder::initGeneratorsSeed() {
  #ifdef DEBUG
		cout << "[HillasEventBuilder] initializing generators seeds.." << endl;
	#endif
  sizeGRNG->initSeed();
  centroidXGRNG->initSeed();
  centroidYGRNG->initSeed();
  majorAxisGRNG->initSeed();
  lenghtGRNG->initSeed();
  widhtGRNG->initSeed();
  #ifdef DEBUG
    cout << "[HillasEventBuilder] Generators initialized.." << endl;
  #endif

}

EventDL2 * HillasEventBuilder::buildDL2Event(int eventId, int telescopeId) {
  #ifdef DEBUG
    cout << "[HillasEventBuilder] building a DL2Event.." << endl;
  #endif

  EventDL2 * dl2Event = new EventDL2(
                                      eventId,
                                      telescopeId,
                                      sizeGRNG     ->getSample(),
                                      centroidXGRNG->getSample(),
                                      centroidYGRNG->getSample(),
                                      majorAxisGRNG->getSample(),
                                      lenghtGRNG   ->getSample(),
                                      widhtGRNG    ->getSample()
                                    );

  return dl2Event;

}
