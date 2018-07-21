/*
 ==========================================================================
 RTA-DL2-Sim C++ https://github.com/ASTRO-EDU/RTA-DL2-Sim

 Copyright (C) 2018 Giancarlo Zollino

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 ==========================================================================
*/

#include<iostream>

// from libRTA.a
#include "FileWriter.h"

#include "HillasEventBuilder.h" // new class


// Nuoooo!!!!
//using namespace std;
//https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice
using std::cout;
using std::endl;
using std::to_string;


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

	if (argc < 2) {
		cout << "randomNumTelescope, Insert '1' to simulate a random number of telescopes, '0' to simulate only one." << endl;
		cout << "eventsNumber, Insert number of events to simulate." << endl;
		return EXIT_FAILURE;
	}

	int randomNumTelescope = atoi(argv[1]);
	int eventsNumber = atoi(argv[2]);

  // PRINT INPUT PARAMETERS -------------------------------------
  cout << "\n" << endl;
  cout << "randomNumTelescope: " << randomNumTelescope << endl;
  cout << "eventsNumber: " << eventsNumber << endl;

  //vector<EventDL2> eventi; // non serve

  //EventDL2 *evento;  // non serve

	#ifdef DEBUG
		cout << "\n** DEBUG MODE ON!!\n" << endl;
		HillasEventBuilder hillasEventBuilder;
		EventDL2 * dl2e1 = hillasEventBuilder.buildDL2Event(666,999);
		EventDL2 * dl2e2 = hillasEventBuilder.buildDL2Event(111,111);
		EventDL2 * dl2e3 = hillasEventBuilder.buildDL2Event(222,222);
		cout << "event: " << dl2e1->toJSONObj() << endl;
		cout << "event: " << dl2e2->toJSONObj() << endl;
		cout << "event: " << dl2e3->toJSONObj() << endl;
	#endif

	#ifdef MULTITHREAD
		cout << "\n** MULTITHREAD MODE ON!!\n" << endl;
	#endif




  string jsonEvents[eventsNumber];  // renamed jsonObj -> jsonEvents

/*
  if ( randomNumTelescope == 0 ) {

    for( int i = 0; i < eventsNumber; i++ ) {

        evento = new EventDL2(i,0);

        jsonEvents[i].append(evento->toJSONObj());

        //eventi.push_back(*evento);
      }


  } else {
*/
    HillasParametersGenerator hillas;


		/*********************************
		/  HillasEventBuilder eventBuilder();   //  possiede 6 distribuzioni (6 coppie media/varianza). Il seed viene inizializzato a riga 96 (per ogni evento)
		/********************************/

		int telescopesNumber = 0; // lo ho spostato su, fuori dal for, è uguale in realtà anche se sta dentro.

    for( int i = 0; i < eventsNumber; i++ ) {




			// questo pezzo di codice va in una funzione: getRndTelescopeNumber(); che inizializza il seed e usa la normal distribution (senza passare
			// per l'HillasParametersGenerator) con una media e varianza ben precisa
			if ( randomNumTelescope == 0 )   // lo testi qua
				telescopesNumber = 1;
			else
				while (telescopesNumber < 2 || telescopesNumber > 10)
	        telescopesNumber = abs(hillas.randomNumberGenarator());


			/**********************************
			/ eventBuilder.initSeeds();
			/********************************/

    	//getchar();

  		for (int j = 0; j < telescopesNumber; j++) {

        EventDL2 * evento = new EventDL2(i,j); //  EventDL2 * evento = eventBuilder.buildRndEvent();

        jsonEvents[i].append(evento->toJSONObj());

				delete(evento);
      	//eventi.push_back(*evento);

  		}

    }

  //}

for( int i = 0; i < eventsNumber; i++ ) {
    string arrJson ="[";
    string nArrJson = jsonEvents[i].substr(0, jsonEvents[i].size()-1);
    arrJson.append(nArrJson);
    arrJson.append("]");
    string name ="dl2Evt";
    name.append(to_string(i));
    name.append(".json");

    FileWriter::write2File(name,arrJson);

  }



  cout << endString << endl;
  return 0;
}
