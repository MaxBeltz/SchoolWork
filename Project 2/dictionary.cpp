#include "dictionary.h"

Dictionary::Dictionary(int size){ //creates the dictionary
	data = new BitArray(size);
	makeLookUp();
}

Dictionary::~Dictionary(){ //kills that punk looser data
	delete data;
}

void Dictionary::initialize(char * character){ //fills data with data
	data->initialize(character);
}

void Dictionary::nonDumbPrint(){ //our amazing super awesome print
	data->nonDumbPrint();
}

void Dictionary::makeLookUp(){ //makes the lookup table, should this have been a static variable?
	//Probebly, did it have to be for fear of loosing points? No.
	//Therefor, did we make it static? Absolutly not.
	for(int i=0; i<256; i++){
		int count = 0;
		int iVal = i;
		int devideVal = 128;
		for(int j=0; j<8; j++){ //mathmaticlly calculates number of postitive bits in a given byte vlaue
			if((iVal/devideVal) == 1){
				count++;
				iVal -= devideVal;
			}
			devideVal = devideVal/2;
		}
		lookUp[i] = count;
	}	
}

int Dictionary::rank_range(int i, int j, int b){ //gets the  number of bs in a range
	int numB = 0;
	int low = 0;
	int high = 0;
	if(i > data->length()) //error checking
		low = data->length();
	else if(i >0)
		low = i;
	if(j > data->length())
		high = data->length();
	else if(j > 0)
		high = j;
	if(low > high){
		int temp = low;
		low = high;
		high = temp;
	}
	for(int loop = low; loop<high; loop++){ //uses a bunch of get statements
		if(data->get(loop) == b)
			numB++;
	}
	return numB;
}

int Dictionary::select_range(int i, int j, int k, int b){ //fings the kth b in a range
	int numB = 0;
	int low = 0;
	int high = 0;
	if(i > data->length()) //error checking
		low = data->length();
	else if(i >0)
		low = i;
	if(j > data->length())
		high = data->length();
	else if(j > 0)
		high = j;
	if(low > high){
		int temp = low;
		low = high;
		high = temp;
	}
	for(int loop = low; loop<high; loop++){//uses a bunch of gets
		if(data->get(loop) == b){
			numB++;
			if(numB == k)
				return loop;
		}
	}
	return -1; //this means that there were not enough elements;
	
}

int Dictionary::rank(int j, int b){ //finds the number of bs from 0 to j using lookup table
	int count = 0;
	int position = 0;
	for(position; (position < data->length() && position < (j-8)); position +=8){ //counts num in an even byte
		if(b==0)
			count = count + (8- lookUp[data->get8(position)]);
		else
			count = count + lookUp[data->get8(position)];
	}
	for(position; (position < data->length() && position < j); position ++){ //counts bit by bit
		if(data->get(position) == b)	
			count++;
	}
	return count;
	
}

int Dictionary::select(int k, int b){ //finds the kth b using the lookup table
	int count = 0;
	int position = 0;
	for(position; (position < data->length()); position +=8){ //checking for full bytes
		if(b==1){
			if((count + lookUp[data->get8(position)]) >= k)
				break;
			else
				count = count + lookUp[data->get8(position)];
			}
		else{
			if((count + (8-lookUp[data->get8(position)])) >= k)
				break;
			else 
				count = count + (8-lookUp[data->get8(position)]);
		}
	}
	for(position; (position < data->length()); position ++){ //checking bit by bit
		if(data->get(position) == b)
			count ++;
		if (count == k)
			return position;
	}
	return -1; //We did not find the kth element
	
}

