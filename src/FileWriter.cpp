/*
 * Copyright (c) 2017
 *     Leonardo Baroncelli, Giancarlo Zollino,
 *
 * Any information contained in this software
 * is property of the AGILE TEAM and is strictly
 * private and confidential.
*/


#include "FileWriter.h"

FileWriter::FileWriter()
{
    //ctor
}

string FileWriter::convertToString(int number){
	std::stringstream out;
	out << number;
	return out.str();
}
string FileWriter::convertToString(float number){
	std::stringstream out;
	out << number;
	return out.str();
}
string FileWriter::convertToString(double number){
	std::stringstream out;
	out << number;
	return out.str();
}

void FileWriter::write2File(string outputFileName,string input){
	ofstream resultOfAnalysis;

	resultOfAnalysis.open(outputFileName.c_str(), std::ofstream::trunc);

	if(resultOfAnalysis.is_open()){
		resultOfAnalysis << input;
		resultOfAnalysis.close();
	}else{
		printf("Cant open header file ");
	}
}



void FileWriter::write2FileAppend(string outputFileName,string input){
	ofstream resultOfAnalysis;

	resultOfAnalysis.open(outputFileName.c_str(), std::ofstream::app);

	if(resultOfAnalysis.is_open()){
		resultOfAnalysis << input;
		resultOfAnalysis.close();
	}else{
		printf("Cant open header file ");
	}
}


/*
void FileWriter::write2JSONFile(string outputFileName,string input){
	ofstream resultOfAnalysis;

	resultOfAnalysis.open(outputFileName.c_str(), std::ofstream::trunc);

	if(resultOfAnalysis.is_open()){
		resultOfAnalysis << "[";
		resultOfAnalysis << input;
		resultOfAnalysis << "]";
		resultOfAnalysis.close();
	}else{
		printf("Cant open header file ");
	}
}
void FileWriter::write2JSONFileAppend(string outputFileName,string input){
	/*ofstream resultOfAnalysis;
	string startChar;
	string endChar;

	resultOfAnalysis.open(outputFileName.c_str(), std::ofstream::app);

	if(resultOfAnalysis.is_open()){
		getline(outputFileName.c_str(), startChar)
		cout << startChar << endl
		if(startChar.compare(0,1,"[")) {
			// in posizione 2 mettere oggetto
		} else if (endChar.compare())
		resultOfAnalysis << input;
		resultOfAnalysis.close();
	}else{
		printf("Cant open header file ");
	}
}*/
