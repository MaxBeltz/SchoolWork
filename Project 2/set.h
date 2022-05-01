// Author(s):
// File: set.h
// Dependencies: bitarray.h
// Compiler: g++
// Contents: A set class that supports union, intersection, and relative complement.

#ifndef SET_H
#define SET_H

#include "bitarray.h"


class Set {

    protected:
       BitArray * data;
       int CARDINALITY;
       
    public:
       // Class maintenance details
       Set(int = 0);                            // constructor
       void initialize(char *);                 // given a character string, set the data appropriately

       ~Set();                                  // default destructor

       // Allow read access to protected variable names
       inline int cardinality() const {return CARDINALITY;};

       // Bit read/write functions
       bool setUnion(Set &);                       // computes the union with the input set and stores it here
       bool intersection(Set &);               // computes the intersection with the input set and stores it here
       bool difference(Set &);                 // computes the relative difference between this set and the input set and stores it here
	   
	   void nonDumbPrint(); 

}; // end class Set

#endif