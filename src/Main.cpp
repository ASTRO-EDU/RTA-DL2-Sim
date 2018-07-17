#include<iostream>


#include <PilParams.h>
#include "Event.h"
#include "FileWriter.h"


using namespace std;

const PilDescription paramsDescr[] = {
    { PilInt, "telescopesNumber", "Input number of telescopes source" },
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

	int telescopesNumber = params["telescopesNumber"];
  int eventsNumber = params["eventsNumber"];

  // PRINT INPUT PARAMETERS -------------------------------------
  cout << "\n" << endl;
  params.Print();


	vector<Event> eventi;
	Event *evento;

	for( int i = 0; i < eventsNumber; i++ ) {

		for (int j = 0; j < telescopesNumber; j++) {

			evento = new Event(i,j);

			eventi.push_back(*evento);

		}

	}


	for( vector<Event> ::iterator it = eventi.begin(); it != eventi.end(); ++it) {
		//it -> Event::PrintInConsole();

	  it -> Event::PrintfInFile();
	}

  cout << endString << endl;
  return 0;
}
