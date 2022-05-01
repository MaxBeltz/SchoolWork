#ifndef CHAINING_H
#define CHAINING_H

#include <list>
#include "HashTable.h"

class chaining:public HashTable{
	private:
		list<int> *table;// = new list<int>[1];
		//list<int> table[1];
		int size;
	
	public:
		chaining();
		~chaining();
	
		virtual int insert(int value);      // Returns 1 if it inserted correctly and 0 if it failed to insert. If an entry was already in the table, return 1.
		virtual int search(int value);      // Returns 1 if the entry was in the table, 0 otherwise.
		virtual int remove(int value);      // Returns 1 if the entry was deleted correctly and 0 if it failed to delete. If the entry was not in the table to begin, return 1.
		virtual int load(string file);      // Returns 1 if the input file was loaded and all entries were inserted correctly, 0 otherwise.
                                            // You may assume that input files do not cause inserts that return 0.
		virtual void print(); 
	


};
#endif