#include<iostream>
#include"HillasParametersGenerator.h"
#include"FileWriter.h"

using namespace std;

class Event {
public:
  Event(int id_event, int id_telescope);
  void PrintInConsole();
  void PrintfInFile();

  struct point {
    double x;
    double y;
  };

  double id_event;
  double id_telescope;
  double size;
  point centroid;
  double mainAxis;
  double lenght;
  double widht;

  string nameFile;
  string eventData;
  string eventDataJSON;

private:


};
