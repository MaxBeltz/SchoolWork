#ifndef SORTNAMESPACE_H
#define SORTNAMESPACE_H

#include <cstdlib>

namespace sorting{
		void merge(int *arr, int left, int middle, int right) {
		int i, j, k;
		int sizeLeftArr = middle - left + 1;
		int sizeRightArr = right - middle;
		int *leftArr = new int[sizeLeftArr], *rightArr = new int[sizeRightArr];
		for (i = 0; i < sizeLeftArr; i++){ 
			leftArr[i] = arr[left + i];
		}
		for (j = 0; j < sizeRightArr; j++) {
			rightArr[j] = arr[middle + 1 + j];
		}
		i = 0;
		j = 0;
		k = left;
		while (i < sizeLeftArr || j < sizeRightArr) {
			if (j >= sizeRightArr || (i < sizeLeftArr && leftArr[i] <= rightArr[j])) {
				arr[k] = leftArr[i];
				i++;
			} else {
				arr[k] = rightArr[j];
				j++;
			}
			k++;
		}
		delete[] leftArr;
		delete[] rightArr;
}
/**
 * Merge sort is a divide and conquer algorithm, it divides the
 * input array into two halves and calls itself for the two halves
 * and then calls merge() to merge the two halves
 *
 * @param arr - array to be sorted
 * @param left - left index or start index of array
 * @param right - right index or end index of array
 *
 */
void mergeSort(int *arr, int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		//middle represents the midpoint of the array for a center split for recursion
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		merge(arr, left, middle, right);
	}
}
	//void mergeSort(int *arr, int left, int right);
	//void merge(int *arr, int left, int middle, int right);
	
	
	int partition(int arr[], int low, int high) {
		int pivot = arr[high];  // taking the last element as pivot
		int smallIndex = (low - 1);      // Index of smaller element

		for (int current = low; current < high; current++) {
			// If current element is smaller than or
			// equal to pivot
			if (arr[current] <= pivot) {
				smallIndex++;  // increment index of smaller element
				int temp = arr[smallIndex];
				arr[smallIndex] = arr[current];
				arr[current] = temp;
			}
		}
		int temp = arr[smallIndex + 1];
		arr[smallIndex + 1] = arr[high];
		arr[high] = temp;
		return (smallIndex + 1);
	}
	/**
	 *      The main function that implements QuickSort
	 *      arr[] --> Array to be sorted,
	 *      low --> Starting index,
	 *      high --> Ending index
	 */
	void quickSort(int arr[], int low, int high) {
		if (low < high) {
			int p = partition(arr, low, high);
			quickSort(arr, low, p - 1);
			quickSort(arr, p + 1, high);
		}
	}
	
	void shellSort(int arr[], int size){
		for (int midpoint = size / 2; midpoint > 0; midpoint = midpoint / 2) {
			for (int obsSecondHalf = midpoint; obsSecondHalf < size; obsSecondHalf++) {
				for (int obsFirstHalf = obsSecondHalf - midpoint; obsFirstHalf >= 0; obsFirstHalf = obsFirstHalf - midpoint) {
					if (arr[obsFirstHalf] < arr[obsFirstHalf + midpoint])
						break;
					else {
						int temp = arr[obsFirstHalf + midpoint];
						arr[obsFirstHalf + midpoint] = arr[obsFirstHalf];
						arr[obsFirstHalf] = temp;
					}
				}
			}
		}			
	}
}

#endif