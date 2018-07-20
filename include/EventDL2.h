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
#include <sstream>
#include <iomanip>
#include"HillasParametersGenerator.h"
//#include"FileWriter.h"

using namespace std;

class EventDL2 {
public:
  EventDL2(int id_event);
  EventDL2(int id_event, int id_telescope);
  ~EventDL2();
  string toJSONObj();
  string toJSONArr(string obj);

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

};
