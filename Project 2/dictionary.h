// Author(s):
// File: dictionary.h
// Dependencies: bitarray.h
// Compiler: g++
// Contents: A dictionary class that supports rank, select, rank_range, and select_range

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "bitarray.h"

class Dictionary {
    // You will need some private variables to set up the lookup tables when you get to that part.
    private:
		int * lookUp = new int[256]; //the lookup table
		
		void makeLookUp(); //method to create the lookup
	
    protected:
		BitArray * data;
       
    public:
       // Class maintenance details
       Dictionary(int = 0);                                        // constructor
       void initialize(char *);                             // given a character string, set the data appropriately

       ~Dictionary();                                       // default destructor
	   void nonDumbPrint();

       // Naive rank/select in a range
       int rank_range(int i, int j, int b = 1);             // computes how many of the bit b are in the interval [i,j), defaults to (b=1)
       int select_range(int i, int j, int k, int b = 1);    // returns the position of the kth bit b in the interval [i,j), defaults to (b=1)
 
       // rank/select using a lookup table
       int rank(int j, int b = 1);                          // computes how many of the bit b are in the interval [0,j), defaults to (b=1)
       int select(int k, int b = 1);                        // returns the position of the kth bit b in the dictionary, defaults to (b=1)
      

}; // end class Set

#endif