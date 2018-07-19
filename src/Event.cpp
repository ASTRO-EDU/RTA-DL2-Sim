#include"Event.h"

Event::Event(int _id_event, int _id_telescope) {



  id_event = _id_event;
  id_telescope = _id_telescope;
  HillasParametersGenerator hillas;
  size = hillas.randomNumberGenarator();
  centroid.x = hillas.randomNumberGenarator();
  centroid.y = hillas.randomNumberGenarator();
  mainAxis = hillas.randomNumberGenarator();
  lenght = hillas.randomNumberGenarator();
  widht = hillas.randomNumberGenarator();

  nameFile = "dl2MTEvt";

  nameFile += FileWriter::convertToString(id_event);

  nameFile.append(".json");

  //FileWriter::write2File(nameFile,eventData);
  /*PrintfInFileMultipleTel();
  eventData = "]";
  FileWriter::write2FileAppend(nameFile,eventData);*/

}

Event::Event(int _id_event) {

  id_event = _id_event;
  HillasParametersGenerator hillas;
  size = hillas.randomNumberGenarator();
  centroid.x = hillas.randomNumberGenarator();
  centroid.y = hillas.randomNumberGenarator();
  mainAxis = hillas.randomNumberGenarator();
  lenght = hillas.randomNumberGenarator();
  widht = hillas.randomNumberGenarator();

  nameFile = "dl2STEvt";

  nameFile += FileWriter::convertToString(id_event);

  nameFile.append(".json");



  //FileWriter::write2File(nameFile,eventData);

}

Event::~Event() {
  // ditruttore
}

string Event::toJSONObj() {

  stringstream obj;

  obj << "{" << "\"id_evt\":" << id_event << ",\"id_tel\":" << id_telescope<< ",\"size\":"<< size <<",\"X\":"<< centroid.x <<",\"Y\":"<<centroid.y<<",\"mAxs\":"<<mainAxis<<",\"lngt\":"<<lenght<<",\"wdt\":"<<widht<<"},";
  string obj2 = obj.str();

  return obj2;
}

string Event::toJSONArr(string obj) {
  string arr = "[";

  arr. append(obj);
  arr.append("]");

  cout << arr << endl;
}

void Event::PrintInConsole() {
  cout << "   ======================================" << endl;
  cout << "Evento: " << id_event << endl;

  cout << "Telescopio: " << id_telescope << endl;

  cout << "Size: " << size << endl;

  cout << "Centroid X: " << centroid.x << endl;

  cout << "Centroid Y: " << centroid.y << endl;

  cout << "MainAxis: " << mainAxis << endl;

  cout << "Lenght: " << lenght << endl;

  cout << "Widht: " << widht << endl;

}

void Event::PrintfInFileSingleTel() {

  eventData += "{\"id_evt\":";

  eventData += FileWriter::convertToString(id_event)+ ",\"size\":";

  eventData += FileWriter::convertToString(size)+ ",\"cX\":";

  eventData += FileWriter::convertToString(centroid.x)+ ",\"cY\":";

  eventData += FileWriter::convertToString(centroid.y)+ ",\"mAxs\":";

  eventData += FileWriter::convertToString(mainAxis)+ ",\"lngt\":";

  eventData += FileWriter::convertToString(lenght)+ ",\"wdt\":";

  eventData += FileWriter::convertToString(widht) + "}";

  eventData += "\n";

  FileWriter::write2FileAppend(nameFile,eventData);

}


void Event::PrintfInFileMultipleTel() {

  eventData = "{\"id_evt\":";

  eventData += FileWriter::convertToString(id_event)+ ",\"id_tel\":";

  eventData += FileWriter::convertToString(id_telescope)+",\"size\":";

  eventData += FileWriter::convertToString(size)+ ",\"cX\":";

  eventData += FileWriter::convertToString(centroid.x)+ ",\"cY\":";

  eventData += FileWriter::convertToString(centroid.y)+ ",\"mAxs\":";

  eventData += FileWriter::convertToString(mainAxis)+ ",\"lngt\":";

  eventData += FileWriter::convertToString(lenght)+ ",\"wdt\":";

  eventData += FileWriter::convertToString(widht) + "},";

  //eventDataM += "]\n";

  FileWriter::write2FileAppend(nameFile,eventData);

}
//cout << obj3 << endl;

/*obj.append("\"id_evt\":");
obj.append(to_string(id_event));

obj.append(",\"id_tel\":");
obj.append(to_string(id_telescope));

obj.append(",\"size\":");
obj.append(to_string(size));

obj.append(",\"X\":");
obj.append(to_string(centroid.x));

obj.append(",\"Y\":");
obj.append(to_string(centroid.y));

obj.append(",\"mAxs\":");
obj.append(to_string(mainAxis));

obj.append(",\"lngt\":");
obj.append(to_string(lenght));

obj.append(",\"wdt\":");
obj.append(to_string(widht));

obj.append("},");

//cout << obj << endl;*/
