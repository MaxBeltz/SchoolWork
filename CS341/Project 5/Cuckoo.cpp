#include "Cuckoo.h"

Cuckoo::Cuckoo(){
	size = 0;
	sizePerTable;
}

Cuckoo::~Cuckoo(){
	delete firstTable;
	delete secondTable;
}

int Cuckoo::insert(int value){
	for(int m=0; m<15; m++){
		if(firstTable[value%sizePerTable] == 0){
			firstTable[value%sizePerTable] = value;
			return 1;
		}
		int temp = firstTable[value%sizePerTable];
		firstTable[value%sizePerTable] = value;
		value = temp;
		if(secondTable[(value/sizePerTable)%sizePerTable] == 0){
			secondTable[(value/sizePerTable)%sizePerTable] = value;
			return 1;
		}
		temp = secondTable[(value/sizePerTable)%sizePerTable];
		secondTable[(value/sizePerTable)%sizePerTable] = value;
		value = temp;
	}
	if(rehash())
		return insert(value);
	return 0;
}

int Cuckoo::search(int value){
	return (firstTable[value%sizePerTable] == value || secondTable[(value/sizePerTable)%sizePerTable] == value);
}

int Cuckoo::remove(int value){
	if(firstTable[value%sizePerTable] == value){
		firstTable[value%sizePerTable] = 0;
		return 1;
	}
	else if(secondTable[(value/sizePerTable)%sizePerTable] == value){
		secondTable[(value/sizePerTable)%sizePerTable] = 0;
		return 1;
	}
	return 0;
}

int Cuckoo::load(string file){
	ifstream infile;
	infile.open(file);
	if(infile.is_open()){
		int tableSize = 0;
		int numInput = 0;
		int numToInsert = 0;
		
		infile >> tableSize;
		infile >> numInput;
		
		size = tableSize;
		sizePerTable = size/2;
		delete firstTable;
		delete secondTable;
		firstTable = new int[sizePerTable]{};
		secondTable = new int[sizePerTable]{};
		
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

void Cuckoo::print(){
	for(int i=0; i<sizePerTable; i++)
		cout <<"[" << i << "]: " << firstTable[i] << "\t\t" << 
			"[" << i << "]: " << secondTable[i] << endl; 
}
                      
int Cuckoo::rehash(){
	if(sizePerTable > 18){
		cout << "Nope, ya done goofed. This cant be salvaged";
		return 0;
	}
	int numItems = 0;
	int store [size];
	for(int i = 0; i< sizePerTable; i++){
		if(firstTable[i] != 0){
			store[numItems] = firstTable[i];
			numItems++;
		}
		if(secondTable[i] != 0){
			store[numItems] = secondTable[i];
			numItems++;
		}
	}
	size+=6;
	sizePerTable+=3;
	delete firstTable;
	delete secondTable;
	firstTable = new int[sizePerTable] {};
	secondTable = new int[sizePerTable] {};
	for(int i=0; i<numItems; i++)
		insert(store[i]);
	return 1;
}