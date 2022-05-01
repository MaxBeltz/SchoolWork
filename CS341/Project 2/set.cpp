#include "set.h"
#include <bitset>

Set::Set(int size){ //creates the set
	data = new BitArray(size);
	CARDINALITY = 0;
}

Set::~Set(){ //demolishes that nerd data
	delete data;
}

void Set::initialize(char * character){ //adds data to data
	data->initialize(character);
}

bool Set::setUnion(Set & compare){ //sets the union of the data by oring each bit
	if(data->length() < compare.data->length())
		return false;
	char first = 0;
	char second = 0;
	for (int i=0; i<compare.data->length(); i++){
		first = data->get(i);
		second = compare.data->get(i);
		data->set(i,(first|second));
		CARDINALITY += first|second;
	}
	return true;
}	

bool Set::intersection(Set & compare){ //sets the intersection of the data by anding each bit
	if(data->length() < compare.data->length())
		return false;
	char first = 0;
	char second = 0;
	for (int i=0; i<compare.data->length(); i++){
		first = data->get(i);
		second = compare.data->get(i);
		data->set(i,(first&second));
		CARDINALITY += first&second;		
	}
	return true;
}

bool Set::difference(Set & compare){ //sets the difference of the data by Xoring each bit
	if(data->length() < compare.data->length())
		return false;
	char first = 0;
	char second = 0;
	for (int i=0; i<compare.data->length(); i++){
		first = data->get(i);
		second = compare.data->get(i);
		data->set(i,(first^second));	
		CARDINALITY += first^second;
	}
	return true;
}

void Set::nonDumbPrint(){ //My super cool print
	data->nonDumbPrint();
}