#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include "HashTable.h"


	class linearProbing: public HashTable{
		private:
			int *table = new int[1]{};
			int size;
		public:
			linearProbing();
			~linearProbing();
			
			virtual int insert(int value);      // Returns 1 if it inserted correctly and 0 if it failed to insert. If an entry was already in the table, return 1.
			virtual int search(int value);      // Returns 1 if the entry was in the table, 0 otherwise.
			virtual int remove(int value);      // Returns 1 if the entry was deleted correctly and 0 if it failed to delete. If the entry was not in the table to begin, return 1.
			virtual int load(string file);      // Returns 1 if the input file was loaded and all entries were inserted correctly, 0 otherwise.
                                                // You may assume that input files do not cause inserts that return 0.
			virtual void print();   






};
#endif