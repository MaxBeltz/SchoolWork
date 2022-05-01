// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// Mbeltz

//how to run
//compile: g++ Slicer.cpp
//run: a.out

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string filename = "";
	string outFile = "";
	string slice = "";
	string lineofCode = "";
	string toPush = "";
	int linenum = 1;
	int start = 0;
	
	cout << "Please enter a file to splice: ";
	cin >> filename;
	ifstream inputFile(filename);
	
	if (inputFile.is_open()){
		cout << "Please enter the variable on which you want to perform the slice: ";
		cin >> slice;
		
		cout << "Please enter the starting line of the slice: ";
		cin >> start;
		
		cout << "Please enter the name of the file you want to store your slice: ";
		cin >> outFile;
		
		ofstream output(outFile);
		if(output.is_open()){
			while (!inputFile.eof())
			{
				getline(inputFile, lineofCode);
				if(lineofCode.find(slice) != string::npos && linenum >= start)
					output << linenum << ": " << lineofCode << endl;
				linenum++;
			}
			output.close();
		}
		else
			cout << "Unable to open file " << outFile << endl;
		inputFile.close();
	}
	else
		cout << "Unable to open file " << filename << endl;
	
}
