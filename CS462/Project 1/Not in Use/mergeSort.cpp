#include "sortNamespace.h"

	/**
	 *
	 * The merge() function is used for merging two halves.
	 * The merge(arr, left, middle, right) is key process that assumes that
	 * arr[left..middle] and arr[middle+1..right] are sorted and merges the two
	 * sorted sub-arrays into one.
	 *
	 * @param arr - array with two halves arr[left...middle] and arr[middle+1...left]
	 * @param left - left index or start index of first half array
	 * @param middle - right index or end index of first half array
	 *
	 * (The second array starts form middle+1 and goes till left)
	 *
	 * @param l - end index or right index of second half array
	 */
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

