// I promise that the work submitted here is solely my own.
//
// mbeltz
#include <cstdlib>
#include <iostream>
#include "sortClass.h"





void show(int *arr, int size) {
    for (int i = 0; i < size; i++){ 
		std::cout << arr[i] << " ";
	}
    std::cout << "\n";
}

/** Main function */
int main() {
    int size(0), method(0);
	Sorts *s;
	//Sorts sort;
    std::cout << "Enter the number of elements : ";
    std::cin >> size;
    int *arr = new int[size];
    std::cout << "Enter the unsorted elements : ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
	std::cout << "What method would you like to use?\n" <<
				"Merge Sort 1\n" <<
				"Quick Sort 2\n" <<
				"Shell Sort 3\n";
	std::cin >> method;
	
	if (method > 0 && method < 4) {
		if (method == 1){
			s = new mergeSort();
		}
		else if (method == 2){
			s = new quickSort();
		}
		else if (method == 3){
			s = new shellSort();
		}
		s->arrange(arr, 0, size - 1);
		std::cout << "Sorted array : ";
		show(arr, size);
	}
	else 
		std::cout << "invalid selection\n";
    delete[] arr;
    return 0;
}
/** @} */