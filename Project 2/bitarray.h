// Author(s): Ankur Gupta
// File: bitarray.h
// Compiler: g++
// Contents: A standard bit array, supporting set and unset.
//           Also includes functions as if it were a finite subset of
//           integers from 0...n.
#include <iostream>
using namespace std;

#ifndef BITARRAY_H
#define BITARRAY_H

class BitArray {

    protected:
       int LENGTH;                              // length of bit array in terms of bits
       int BYTES;                               // number of bytes required for bit array
       char * data;                             // the bit array itself

    public:
       // Class maintenance details
       BitArray(int = 0);                       // constructor
       void clear();                            // set all bits to 0
       void initialize(char*);                  // given a character string, copy its contents here

       ~BitArray();                             // default destructor

       // Allow read access to protected variable names
       inline int length() const {return LENGTH;}
       inline int bytes() const {return BYTES;}
	   
	   void nonDumbPrint(); 

       // This function allows easy printing of a bit array
       // This is an overloaded operator for the <<, so that you can cout a BitArray
       friend ostream & operator << (ostream &, BitArray &);

       // Bit read/write functions
       bool set(int p,int b=1);                // sets a bit b (default 1) at position p
       bool flip(int p);                       // flips the bit at position p
       char get(int p);                        // returns the value of the bit at position p
       
       // Functions for later, you will have to reimplement this to get Question 3 to work.
       char get8(int p) {return data[p/8];}            // return a char that contains the decimal version of the bit interval [p,p+8).
       // Hint: You may need to recast the return value of get to treat it like an unsigned int, but the char return value will be useful.
       
       // Functions that operate on the whole array
       void complement();                      // flips 1's and 0's in bit array
}; // end class BitArray




#endif