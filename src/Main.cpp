#include<iostream>


#include <PilParams.h>
#include "Event.h"
#include "FileWriter.h"


using namespace std;

const PilDescription paramsDescr[] = {
    { PilBool, "singleTelescope", "'Yes' (or 'y')  to simulate only one telescope, 'No' (or 'n') to simulate more than one" },
    { PilInt, "eventsNumber", "Input number of events source to simulate" },
    { PilNone, "", "" }
};

const char* startString = {
"################################################################\n"
"###                   - Task dl2-Simulator -                 ###"
};

const char* endString = {
"### Task dl2-Simulator exiting ............................... ###\n"
"################################################################"
};



int main(int argc, char *argv[])
{

	cout << startString << endl;

	PilParams params(paramsDescr);
    if (!params.Load(argc, argv))
        return EXIT_FAILURE;

	bool singleTelescope = params["singleTelescope"];
  int eventsNumber = params["eventsNumber"];

  // PRINT INPUT PARAMETERS -------------------------------------
  cout << "\n" << endl;
  params.Print();

  vector<Event> eventi;

  Event *evento;

  string jsonObj[eventsNumber];

  if ( singleTelescope == true ) {

    for( int i = 0; i < eventsNumber; i++ ) {

        evento = new Event(i,0);

        jsonObj[i].append(evento->toJSONObj());

        eventi.push_back(*evento);
      }


  } else {

    HillasParametersGenerator hillas;

    for( int i = 0; i < eventsNumber; i++ ) {

      int telescopesNumber = 0;

      while (telescopesNumber < 2 || telescopesNumber > 10) {
        telescopesNumber = abs(hillas.randomNumberGenarator());
        //cout << "Telescope number: " << telescopesNumber << endl;
      }
      //getchar();

  		for (int j = 0; j < telescopesNumber; j++) {

        evento = new Event(i,j);

        jsonObj[i].append(evento->toJSONObj());

      	eventi.push_back(*evento);

  		}

    }

  }

for( int i = 0; i < eventsNumber; i++ ) {
    string arrJson ="[";
    string nArrJson = jsonObj[i].substr(0, jsonObj[i].size()-1);
    arrJson.append(nArrJson);
    arrJson.append("]");
    string nameId = jsonObj[i].substr(10, 1);
    string name ="dl2";
    name.append(nameId);
    name.append(".json");
    //cout << arrJson << endl;
    FileWriter::write2File(name,arrJson);

  }

  cout << endString << endl;
  return 0;
}
