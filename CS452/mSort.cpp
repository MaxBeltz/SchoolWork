#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include "mpi.h" // message passing interface
#include <cstdlib>
using namespace std;

 //New compile and run commands for MPI!
 //mpicxx -o blah file.cpp
 //mpirun -q -np 32 blah

void mergesort (int * a, int first, int last);
void merge(int * a, int * b, int lasta, int lastb, int * output = NULL);

void mergesort(int * a, int first, int last){
	if (last <= first) //if we only have one element
		return;
	if (first+1 == last) //if we have 2 elements
	{
		if (a[first] > a[last]) //if the first element is greater than the secong
		{
			int temp = a[first]; //swap them
			a[first] = a[last];
			a[last] = temp;
		}
		return;
	}
	int mid = (first + last)/2; //get the new midpoint
	mergesort(a, first, mid); //sort the first half
	mergesort(a, mid+1, last); //sort the second half
	//cout << first << " " << mid << " " << last << endl;
	//uncomment if you don't believe this works
	merge(&a[first],&a[mid+1],mid-first,last-mid);	 //merge the completed list together
	//&a[first] the first array will go from the starting point to the mid 
	//&a[mid+1] the second array will go from the mid to the end
	//I know you said the above was the issue but it was not
	//if n=13 the final observation first=0, second=6, last=12
	//the first array will go from 0-6, 7 items an the second array will go from 7-12, 6 items
	//mid-first the lasta item will be indexed from 0 to the total number of items
	//last-first the lastb item will be indexed from 0 to the total number of items
}

void merge(int * a, int * b, int lasta, int lastb, int * output){
	if (output == NULL) //if they dont give an output
		output = a;
	//cout << lasta << " " << lastb << endl;
	//uncomment if you dont believe me that the arrays are even
	int * first = new int [lasta+1]; //create first dummy array note error was fixed with +1
	int * second = new int [lastb]; //create second dummy array
	for (int i=0; i<=lasta; i++){ //fill the first array
		first[i] = a[i];
	}
	for (int i=0; i<lastb; i++){ //fill the second array
		second[i] = b[i];
	}
	//uncomment if you dont believe that the arrays are even
	/*for (int i=0; i<=lasta; i++)
		cout << first[i] << " ";
	cout << endl;
	for (int i=0; i<lastb; i++)
		cout << second[i] << " ";
	cout << endl;*/
	int firstCount = 0; //counter for the first array
	int secondCount = 0; //counter for the second array
	int current = 0; //the current position in the output  array
	while(firstCount <= lasta && secondCount < lastb){ //while we have room in both arrays
		
		if (first[firstCount] < second[secondCount]){ //if the item in the first array is less 
			output[current] = first[firstCount]; //place it in the output
			firstCount++;
			current++;
		}
		else{ //if the second item is larger or they are equal
			output[current] = second[secondCount]; //fill in the second item 
			secondCount++;
			current++;
		}
	}
	for(firstCount; firstCount <= lasta; firstCount++){ //will fill in the rest of the first array if the second array ran out
		output[current] = first[firstCount];
		current++;
	}
	for(secondCount; secondCount < lastb; secondCount++){ //will fill in the rest of the second array if the first array ran out
		output[current] = second[secondCount];
		current++;
	}
	//cout << endl;
	delete [] first;
	delete [] second;
}


int main (int argc, char * argv[]) {

	int my_rank = 0;			// my CPU number for this process
	int p;					// number of CPUs that we have
	int source;				// rank of the sender
	int dest;				// rank of destination
	int tag = 0;			// message number
	char message[100];		// message itself
	MPI_Status status;		// return status for receive
	
	// Start MPI
	MPI_Init(&argc, &argv);
	
	// Find out my rank!
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	// Find out the number of processes!
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	
	// THE REAL PROGRAM IS HERE
	if (my_rank == 0){ //will only be run by the origional array
		cout << "How many items?: ";
		int n; 
		cin >> n; //user determines list size
		int * a = new int [n];
		for (int i=0; i<n; i++)//fills the list
			a[i] = (rand()%1000000);
		cout << "The Unsorted List: ";
		for (int i=0; i<n; i++) //outputs the unsorted array
			cout << a[i] << " ";
		cout << endl << endl << endl; //adds space
		mergesort(a,0,n-1); //sorts the array
		cout << "The Sorted List: ";
		for (int i=0; i<n; i++) //prints the sorted array
			cout << a[i] << " ";
		cout << endl << endl;
		delete [] a;
	}
	// Shut down MPI
	MPI_Finalize();

	return 0;
}