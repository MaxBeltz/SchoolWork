#include "linearProbing.h"

linearProbing::linearProbing(){
	size = 0;
}

linearProbing::~linearProbing(){
	delete table;
}

int linearProbing::insert(int value){
	if (value > 999 || value < 1 || size == 0)
		return 0;
	for(int i = 0; i<size; i++){
		if(table[((value%size)+i)%size] == 0){
			table[((value%size)+i)%size] = value;
			return 1;
		}
	}
	return 0;
}	

int linearProbing::search(int value){
	if (value > 999 || value < 1 || size == 0)
		return 0;
	for(int i = 0; i<size; i++){
		if(table[((value%size)+i)%size] == value)
			return 1;
	}
	return 0;
}

int linearProbing::remove(int value){
	if (value > 999 || value < 1 || size == 0)
		return 0;
	for(int i = 0; i<size; i++){
		if(table[((value%size)+i)%size] == value){
			table[((value%size)+i)%size] = 0;
			return 1;
		}
	}
	return 0;
}

int linearProbing::load(string file){
	ifstream infile;
	infile.open(file);
	if(infile.is_open()){
		int tableSize = 0;
		int numInput = 0;
		int numToInsert = 0;
		
		infile >> tableSize;
		infile >> numInput;
		
		size = tableSize;
		delete table;
		table = new int[size]{};
		
		for(int i=0; i<numInput; i++){
			infile >> numToInsert;
			insert(numToInsert);
		}
		return 1;
	}	
	else{
		cout << "Invalid File Ya Goober" << endl;
	return 0;
	}
}

void linearProbing::print(){
	for(int i=0; i<size; i++)
		cout <<"[" << i << "]: " << table[i] << endl; 
}