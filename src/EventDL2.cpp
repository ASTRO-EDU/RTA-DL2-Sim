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

#include"EventDL2.h"

EventDL2::EventDL2(int _id_event, int _id_telescope) {



  id_event = _id_event;
  id_telescope = _id_telescope;
  HillasParametersGenerator hillas;
  size = hillas.randomNumberGenarator();
  centerX = hillas.randomNumberGenarator();
  centerY = hillas.randomNumberGenarator();
  mainAxis = hillas.randomNumberGenarator();
  lenght = hillas.randomNumberGenarator();
  widht = hillas.randomNumberGenarator();

}

EventDL2::EventDL2(int _id_event) {

  id_event = _id_event;
  HillasParametersGenerator hillas;
  size = hillas.randomNumberGenarator();
  centerX = hillas.randomNumberGenarator();
  centerY = hillas.randomNumberGenarator();
  mainAxis = hillas.randomNumberGenarator();
  lenght = hillas.randomNumberGenarator();
  widht = hillas.randomNumberGenarator();

}

EventDL2::~EventDL2() {
  // ditruttore
}

string EventDL2::toJSONObj() {

  stringstream obj;

  obj << "{" << "\"id_evt\":" << id_event << ",\"id_tel\":" << id_telescope<< ",\"size\":"<< size <<",\"X\":"<< centerX <<",\"Y\":"<< centerY <<",\"mAxs\":"<<mainAxis<<",\"lngt\":"<<lenght<<",\"wdt\":"<<widht<<"},";
  string obj2 = obj.str();

  return obj2;
}
