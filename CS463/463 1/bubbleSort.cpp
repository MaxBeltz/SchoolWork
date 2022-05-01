#include "bubbleSort.h"


bubbleSort::bubbleSort(int numArray[], int size)
{
	//Set newArray values and size
	array_size = size;
	for (int i = 0; i < size; i++)
	{
		newArray[i] = numArray[i];
	}

}
void bubbleSort::numSort()
{
	/*
		Sorts up.
		Run thru the array with a for loop and check if a number i is greater then a number i+1.
		If so swap those numbers and compare the bigger number to the next number.  Sort by larger numbers.
		If the bigger value is larger than the next value swap and keep going until there is a larger number.
		Everytime a number swaps it sets swap var to true so it runs thru the array again.
		it will do this everytime a number is swapped so that when no numbers are swapped the sortting is complete.
	

		Big-O 
		The worst case runtime equation is: O(n^2)
		


	*/
	int temp, i, j=0;
	bool swap;
	swap = true;
	while(swap)
	{
		swap = false;
		j++;
		for (i = 0; i<array_size-j; i++)
		{
			if (newArray[i] > newArray[i+1])
			{
				temp = newArray[i];
				newArray[i] = newArray[i+1];
				newArray[i+1] = temp;
				swap = true;
			}
		}
	}
	
	// print the sorted array
	std::cout << "\n\nBubble Sort: ";
	for (int i = 0; i < array_size; i++)
	{
		std::cout << newArray[i] << ",";
	}
}

// bubbleSort::~bubbleSort()
// {

// }