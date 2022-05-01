#include "chaining.h"

chaining::chaining(){
	size = 1;
}

chaining::~chaining(){
	delete[] table;
	table = nullptr;
}

int chaining::insert(int value){
	if (value > 999 || value < 1 || size == 0)
		return 0;
	int place = value%size;
	table[place].push_back(value);
	return 1;
}

int chaining::search(int value){
	if (value > 999 || value < 1 || size == 0)
		return 0;
	int place = value%size;
	for (list<int>::iterator x = table[place].begin(); x != table[place].end(); x++){
		if(*x == value)
			return 1;
	}
	return 0;
}

int chaining::remove(int value){
	if (value > 999 || value < 1 || size == 0)
		return 0;
	int place = value%size;
	if(search(value)){
		table[place].remove(value);
		return 1;
	}
	return 0;
}

int chaining::load(string file){
	ifstream infile;
	infile.open(file);
	if(infile.is_open()){
		int tableSize = 0;
		int numInput = 0;
		int numToInsert = 0;
		
		infile >> tableSize;
		infile >> numInput;
		
		size = tableSize;
		//delete table;
		table = new list<int>[size];
		
		for(int i=0; i<numInput; i++){
			infile >> numToInsert;
			insert(numToInsert);
		}
	}	
	else{
		cout << "Invalid File Ya Goober" << endl;
		return 0;
	}
	infile.close();
	return 1;
}

void chaining::print(){
	for(int i=0; i<size; i++){
		cout <<"[" << i << "]: ";
		for (list<int>::iterator x = table[i].begin(); x != table[i].end(); x++)
			cout << *x << " ";
		cout << endl;
	}
}
