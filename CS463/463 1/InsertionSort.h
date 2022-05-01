#ifndef INSERT_H
#define INSERT_H

#include <iostream>

#include "Sort.h"


class insertSort: public Sort
{
private:
	//create a blank array to populate with incoming array
	int newArray[50];
	int array_size;
public:
	//Set array and size
	insertSort(int numArray[], int size);
	//Sort the array
	virtual void numSort();

	~insertSort();
};

#endif
