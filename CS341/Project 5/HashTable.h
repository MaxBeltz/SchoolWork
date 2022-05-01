#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// This is defined as a pure virtual class, since no implementations are provided the majority
// of the functions, you MUST write implementations for them in all derived classes.
// As a reminder, a pure virtual function (one that must be redefined) has an "= 0" at the end of it.

class HashTable {
    private:
        int m;                                  // Size of the internal table(s)
        
	public:
        // Class setup
        HashTable() {};                         // You might want to set this function up with a default parameter to support that behavior for derived classes.
        virtual ~HashTable() {};               // This is a pure virtual function, but since it's a destructor, it's called from every derived class destructor as well.
                                                // You need to specify its description, which I've done below. This form allows you to indicate that it's pure (that all
                                                // derived classes must redefine it, but then it will still work afterwards.
		
        // Core functionality
        virtual int insert(int value) = 0;      // Returns 1 if it inserted correctly and 0 if it failed to insert. If an entry was already in the table, return 1.
        virtual int search(int value) = 0;      // Returns 1 if the entry was in the table, 0 otherwise.
        virtual int remove(int value) = 0;      // Returns 1 if the entry was deleted correctly and 0 if it failed to delete. If the entry was not in the table to begin, return 1.
        virtual int load(string file) = 0;      // Returns 1 if the input file was loaded and all entries were inserted correctly, 0 otherwise.
                                                // You may assume that input files do not cause inserts that return 0.
        virtual void print() = 0;               // Print the table in a pretty way that is useful to look at. You will need to use your iomanip-fu to make this beautiful. Be ready.
        
}; // end class HashTable

// Destructor
//HashTable::~HashTable() {}

#endif