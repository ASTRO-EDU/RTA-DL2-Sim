#include<iostream>
#include"HillasParametersGenerator.h"
#include"FileWriter.h"
#include <sstream>
#include <iomanip>

using namespace std;

class Event {
public:
  Event(int id_event);
  Event(int id_event, int id_telescope);
  ~Event();
  void PrintInConsole();
  void PrintfInFileSingleTel();
  void PrintfInFileMultipleTel();
  string toJSONObj();
  string toJSONArr(string obj); //,int nElem

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
  string jsonObj;

  string nameFile;
  string nameFileMTel;
  string eventData;

private:


};
