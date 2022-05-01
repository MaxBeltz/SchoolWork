#ifndef BUBBLE_H
#define BUBBLE_H

#include <iostream>

#include "Sort.h"


class bubbleSort: public Sort
{
protected:
	//create a blank array to populate with incoming array
	int newArray[50];
	int array_size;
public:
	// Set array and size
	bubbleSort(int numArray[], int size);
	//Sorting algorithm
	virtual void numSort();
	
	~bubbleSort();
};

#endif