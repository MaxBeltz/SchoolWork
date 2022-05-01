#ifndef CUCKOO_H
#define CUCKOO_H

#include "HashTable.h"

class Cuckoo:public HashTable{
	private:
		int *firstTable = new int[1] {};
		int *secondTable = new int[1] {};
		int size;
		int sizePerTable;

	public:
		Cuckoo();
		~Cuckoo();
		
		virtual int insert(int value);      // Returns 1 if it inserted correctly and 0 if it failed to insert. If an entry was already in the table, return 1.
		virtual int search(int value);      // Returns 1 if the entry was in the table, 0 otherwise.
		virtual int remove(int value);      // Returns 1 if the entry was deleted correctly and 0 if it failed to delete. If the entry was not in the table to begin, return 1.
		virtual int load(string file);      // Returns 1 if the input file was loaded and all entries were inserted correctly, 0 otherwise.
                                            // You may assume that input files do not cause inserts that return 0.
		virtual void print(); 
		
		int rehash();


};
#endif