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

  nameFile = "dl2Evt";
  nameFile += FileWriter::convertToString(id_event);
  nameFile.append(".json");


  FileWriter::write2File(nameFile,eventData);
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

void Event::PrintfInFile() {

  eventData = "{ \"id_event\" : ";

  eventData += FileWriter::convertToString(id_event)+ " , \"id_telescope\" : ";

  eventData += FileWriter::convertToString(id_telescope)+" , \"size\" : ";

  eventData += FileWriter::convertToString(size)+ " , \"centroidX\" : ";

  eventData += FileWriter::convertToString(centroid.x)+ " , \"centroidY\" : ";

  eventData += FileWriter::convertToString(centroid.y)+ " , \"mainAxis\" : ";

  eventData += FileWriter::convertToString(mainAxis)+ " , \"lenght\" : ";

  eventData += FileWriter::convertToString(lenght)+ " , \"widht\" : ";

  eventData += FileWriter::convertToString(widht) + " }\n";
  
  FileWriter::write2FileAppend(nameFile,eventData);

}
