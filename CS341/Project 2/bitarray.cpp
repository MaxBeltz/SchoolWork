#include "bitarray.h"
#include <bitset>

BitArray::BitArray(int value) { //created the bitArray
	BYTES = value;
	LENGTH = 8*value;
	data = new char [BYTES];
}



void BitArray::clear() { //clears the data array
	for(int i = 0; i < BYTES; i++) {
		data[i] = 0; 
	}
	
}

void BitArray::initialize(char * character) { //adds data to the array
	for(int i = 0; i < sizeof(character) && i < BYTES; i++) {
		data[i] = character[i];
	}
}

BitArray::~BitArray() { //destroys that nerd data
	delete data;
}



ostream & operator << (ostream & out, BitArray & array) { //Gupta's dumb print
   int NUMPERLINE = 4;
   int numPrinted = 0;
   for (int x = 0; x < array.length(); x++) {
      if (array.get(x)) {
         out.width(4);
         out << x;
         numPrinted++;
         if (numPrinted % NUMPERLINE == 0)
            out << "\n";
      } // end if
   } // end for
   return out;
} // end ostream & operator <<

bool BitArray::set(int p, int b) { //set
	if(p > LENGTH|| (b !=1 && b!=0) ) { return false;}
	int arrayPosition = p/8;
	int bitPosition = p%8;
	
	char set = 1;
	for( int i = 0; i < bitPosition; i++) {
		set *= 2;
	}
	if( b == 1) { //if set to 1, or the byte with the bit to a byte of all 0s and 1 1 in the bit position
		data[arrayPosition]= (data[arrayPosition] | set);
	}
	else { //if set to 0, and the byte with a bit of all 1s and 0 at the bit position
		char notset = ~set;
		data[arrayPosition]= (data[arrayPosition] & notset);
	}
	return true;
}

bool BitArray::flip(int p) { //used to flip the bit of the position 
	if(p > LENGTH) { return false;}
	int arrayPosition = p/8;
	int bitPosition = p%8;
	
	char flip = 1;
	for( int i = 0; i < bitPosition; i++) { //exclusinve or with a 1 in the position
		flip *= 2;
	}
	data[arrayPosition] = (data[arrayPosition] ^ flip);
	return true;
}
char BitArray::get(int p) { //returns the value of the bit in the postion
	int arrayPosition = p/8;
	int bitPosition = p%8;
	char flip = 1;
	for( int i = 0; i < bitPosition; i++) {
		flip *= 2;
	}
	if ((data[arrayPosition] & flip) > 0)
		return 1;
	return 0;
}
void BitArray::complement() {
	for(int i =0; i< 8; i++) {
		data[i] = ~data[i];
	}
}

void BitArray::nonDumbPrint() { //our super cool and easy to read print
	for (int i=0; i<BYTES; i++)
		std::cout << (bitset<8>)data[i] << std::endl ;
}
