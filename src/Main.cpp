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

#include "EventDL2.h"
#include "FileWriter.h"


using namespace std;


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

  int randomNumTelescope = atoi(argv[1]);
  int eventsNumber = atoi(argv[2]);

  // PRINT INPUT PARAMETERS -------------------------------------
  cout << "\n" << endl;
  cout << "randomNumTelescope: " << randomNumTelescope << endl;
  cout << "eventsNumber: " << eventsNumber << endl;

  vector<EventDL2> eventi;

  EventDL2 *evento;

  string jsonObj[eventsNumber];

  if ( randomNumTelescope == 0 ) {

    for( int i = 0; i < eventsNumber; i++ ) {

        evento = new EventDL2(i,0);

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

        evento = new EventDL2(i,j);

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
    string name ="dl2Evt";
    name.append(to_string(i));
    name.append(".json");

    FileWriter::write2File(name,arrJson);

  }

  cout << endString << endl;
  return 0;
}
