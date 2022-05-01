#include "InsertionSort.h"


insertSort::insertSort(int numArray[], int size)
{
	//Set newArray values and size
	array_size = size;
	for (int i = 0; i < size; i++)
	{
		newArray[i] = numArray[i];
	}

}

void insertSort::numSort()
{
	/*
		
		sorts down.
		Starts at j and compares to j-1
		if j is less than j-1 swap 
		while that number is smaller than the number befor it keep swapping down until its larger than the number before it.
		when that number is larger than the number before it, while is not true.
		Then set j = i again and check the condition for the while loop once more if true run thru the while until sorted
		A bit slower than bubble sort because for every number smaller than the one before it you have to run thru a while loop
		and compare to every number before it. Not as fast for larger arrays.

		Big-O 
		The worst case Time Complexity function: O(n^2)

		The eqn in terms of space complexity is: O(n^2)

	*/
	int temp, j, i;
	for (i = 0; i < array_size; i++)
	{
		j=i;
		while (j > 0 && newArray[j] < newArray[j-1])
		{
			temp = newArray[j];
			newArray[j] = newArray[j-1];
			newArray[j-1] = temp;
			j--;
		}
	}

	//Print array
	std::cout << "\n\nInsertion Sort: ";
	for (int i = 0; i < array_size; i++)
	{
		std::cout << newArray[i] << ",";
	}
}