#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "mpi.h" // message passing interface
#include <math.h>
using namespace std;

// New compile and run commands for MPI!
// mpicxx -o blah file.cpp
// mpirun -q -np 32 blah

void mergesort(int * a, int first, int last);
void smerge(int * a, int * b, int lasta, int lastb, int * output = NULL);
int ranks(int * a, int first, int last, int valToFind);
void pmerge(int * a, int * b, int lasta, int lastb, int * output = NULL);
int my_rank;			// my CPU number for this process
int p;					// number of CPUs that we have
int tag = 0;			// message number
int source;				// rank of the sender
int dest;				// rank of destination
char message[100];		// message itself
MPI_Status status;		// return status for receive

//
//written by Max Beltz and Ian Wallack
//	

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
	smerge(&a[first],&a[mid+1],mid-first+1,last-mid);	 //merge the completed list together
}

void smerge(int * a, int * b, int lasta, int lastb, int * output){
	//cout << "last A " << lasta << " Last B " << lastb << endl;
	if (output == NULL) //if they dont give an output
		output = a;
	int * first = new int [lasta]; //create first dummy array note error was fixed with +1
	int * second = new int [lastb]; //create second dummy array
	for (int i=0; i<lasta; i++){ //fill the first array
		first[i] = a[i];
	}
	for (int i=0; i<lastb; i++){ //fill the second array
		second[i] = b[i];
	}
	int firstCount = 0; //counter for the first array
	int secondCount = 0; //counter for the second array
	int current = 0; //the current position in the output  array
	while(firstCount < lasta && secondCount < lastb){ //while we have room in both arrays
		
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
	for(firstCount; firstCount < lasta; firstCount++){ //will fill in the rest of the first array if the second array ran out
		output[current] = first[firstCount];
		current++;
	}
	for(secondCount; secondCount < lastb; secondCount++){ //will fill in the rest of the second array if the first array ran out
		output[current] = second[secondCount];
		current++;
	}
	delete [] first;
	delete [] second;
}

int ranks(int * a, int first, int last, int valToFind){ //ranking function
	int mid = (first + last)/2;
	int curRank = 0;
	if(first+1 == last){ //once the searced for value is near its rank
		if (valToFind > a[last])
			return (last+1);
		else if (valToFind > a[first])
			return last;
		else 
			return first;
	}
	else if(valToFind > a[mid]) //recurse
		curRank = ranks(a, mid, last, valToFind);
	else if(valToFind < a[mid])
		curRank = ranks(a, first, mid, valToFind);
	else
		curRank = mid-1;
	return curRank;	
}

void pmerge(int * a, int * b, int lasta, int lastb, int * output){//chack condition for different sized lists
	if (output == NULL) //if they dont give an output
		output = a;
	if(lasta ==1 && lastb==1)
	{
		if (a[0] > b[0]) //if the first element is greater than the secong
		{
			output[1] = a[0]; //swap them
			output[0] = b[0];
		}
		return;
	}
	int loga = log2(lasta); //log base 2 of a
	int inca =((lasta-1)/loga)+1; //num of items for shape, a remanent of when we thought we needed every value
	int logb = log2(lastb); //log base 2 of a
	int incb =((lastb-1)/logb)+1; //num of items for shape, a remanent of when we thought we needed every value
	int shapeA[2*inca] = {0}; //the indexes for the shape of A
	int shapeB[2*incb] = {0}; //the indexes for the shape of B
	int localsRanka[2*inca] = {0}; //Local ranks for A
	int localsRankb[2*incb] = {0}; //Local ranks for B
	int localOutput[lasta+lastb] = {0};// where we shove the local shapes into
	
	//NOTE any commented out code can be uncommented for testing purposes
	
	/*if(my_rank == 0){
		cout << "Last A " << lasta << " Last B " << lastb << endl;
		cout << "Unsorted big array ";
		for(int i=0; i<lasta+lastb; i++)
			cout << a[i] << " ";
		cout << endl;
	}*/
	
	if (lasta>3){ //recursive statement with base case 3 and below
		if (lasta%2==0) //from when we thought we had to deal with this
			pmerge(&a[0], &a[lasta/2], lasta/2, lasta/2);
		else
			pmerge(&a[0], &a[lasta/2], lasta/2, lasta/2+1);
	}
	else{
		/*if (my_rank==0){
			cout << "A[0] " << a[0] << " Last A " << lasta;
			cout << endl;
		}*/
		mergesort(&a[0], 0, lasta-1);
		/*if (my_rank==0){
			cout << "sorted A big array ";
			for(int i=0; i<lasta+lastb; i++)
				cout << a[i] << " ";
			cout << endl;
		}*/
	}
	if (lastb>3){
		if (lastb%2==0)
			pmerge(&b[0], &b[lastb/2], lastb/2, lastb/2);
		else 
			pmerge(&b[0], &b[lastb/2], lastb/2, lastb/2+1);
	}
	else{
		/*if (my_rank==0){
			cout << "B[0] " << b[0] << " Last B " << lastb;
			cout << endl;
		}*/
		mergesort(&b[0], 0, lastb-1);
		/*if (my_rank==0){
			cout << "sorted B big array ";
			for(int i=0; i<lasta+lastb; i++)
				cout << a[i] << " ";
			cout << endl;
		}*/
	}
	
	if(!(lasta<=3 && lastb<=3)){ //this if statement is a relic from the before time of difficult problem
		/*if(my_rank == 0){
			cout << "Semisorted big array ";
			for(int i=0; i<lasta+lastb; i++)
				cout << a[i] << " ";
			cout << endl;
		}*/
		
		for(int i=my_rank*loga; i<lasta; i+= p*loga){ //calculate local ranks for a
			localsRanka[i/loga] = ranks(a, 0, lastb-1, b[i]);
			localsRanka[inca+i/loga] = i;
		}
			
		for(int i=my_rank*logb; i<lastb; i+= p*logb){ //for b
			localsRankb[i/logb] = ranks(b, 0, lasta-1, a[i]);
			localsRankb[incb+i/logb] = i;
		}
			
		MPI_Reduce(localsRanka, shapeA, 2*inca, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD); //give the ranks to everyone
		MPI_Reduce(localsRankb, shapeB, 2*incb, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
			
		/*if (my_rank == 0){
			cout << "S Rank A ";
			for (int i=0; i<2*inca; i++)
				cout << shapeA[i] << " ";
			cout << endl;
			cout << "S Rank B ";
			for (int i=0; i<2*incb; i++)
				cout << shapeB[i] << " ";
			cout << endl;
		}*/

		if (my_rank == 0){
			/*cout << "Last A " << lasta << " Last B " << lastb << endl;
			cout << "inca " << inca << " incb " << incb << endl;
			cout << "shapeA[0]:" << shapeA[0] << " shapeA[inca]:" << shapeA[inca] << endl;
			cout << "shapeB[0]:" << shapeB[0] << " shapeB[incb]:" << shapeB[incb] << endl;*/
			smerge(&shapeA[0], &shapeA[inca], inca , inca); //sort the list of shape endpoints
			smerge(&shapeB[0], &shapeB[incb], incb , incb);
		}
		
		/*if (my_rank == 0){
			cout << "S Rank A ";
			for (int i=0; i<2*inca; i++)
				cout << shapeA[i] << " ";
			cout << endl;
			cout << "S Rank B ";
			for (int i=0; i<2*incb; i++)
				cout << shapeB[i] << " ";
			cout << endl << endl;
		}*/
			
		MPI_Bcast(shapeA, 2*inca, MPI_INT, 0, MPI_COMM_WORLD); //send out the shape endpoints
		MPI_Bcast(shapeB, 2*inca, MPI_INT, 0, MPI_COMM_WORLD);
		
		/*if (my_rank == 0){
			cout << "inca:" << inca << " incb:" << incb << endl;
			cout << "Sorted S Rank A ";
			for (int i=0; i<2*inca; i++)
				cout << shapeA[i] << " ";
			cout << endl;
			cout << "Sorted S Rank B ";
			for (int i=0; i<2*incb; i++)
				cout << shapeB[i] << " ";
			cout << endl;
			cout << "Last A " << lasta << " Last B " << lastb << endl;
		}*/
			
			for(int i=my_rank; i<(2*inca-1); i+=p){ //sort the list
				//cout << "A Start " << shapeA[i] << " B Start " << shapeB[i] << endl;
				//cout << "A End " <<  shapeA[i+1]-shapeA[i] << " B End " << shapeB[i+1]-shapeB[i] << endl;
				//cout << "C position " << shapeA[i]+shapeB[i] << endl; 
				smerge(&a[shapeA[i]], &b[shapeB[i]], 
				shapeA[i+1]-shapeA[i], shapeB[i+1]-shapeB[i], 
				&localOutput[shapeA[i]+shapeB[i]]);
			}
				
		if(my_rank==0){ //the final shape
			//cout << "A Start " << shapeA[2*inca-1] << " B Start " << shapeB[2*incb-1] << endl;
			//cout << "A End " <<  lasta-shapeA[2*inca-1] << " B End " << lastb-shapeB[2*incb-1] << endl;
			//cout << "C position " << shapeA[2*inca-1]+ shapeB[2*incb-1] << endl; 
			smerge(&a[shapeA[2*inca-1]], &b[shapeB[2*incb-1]], 
			lasta-shapeA[2*inca-1], lastb-shapeB[2*incb-1],
			&localOutput[shapeA[2*inca-1]+ shapeB[2*incb-1]]);
		}
		/*cout << "My Rank: " << my_rank << " Local Array ";
		for(int i=0; i<lasta+lastb; i++)
			cout << localOutput[i] << " ";
		cout << endl << endl;*/
			
		MPI_Allreduce(localOutput, output, lasta+lastb, MPI_INT, MPI_SUM, MPI_COMM_WORLD); //take in the sorting
			
		/*if(my_rank==0){
			cout << "Sorted Array : ";
			for(int i=0; i<lasta+lastb; i++)
				cout << output[i] << " ";
			cout << endl << endl;
		}*/
	}
	else {
		smerge(&a[0], &b[0], lasta, lastb);
		/*if(my_rank==0){
			cout << "Last A " << lasta << " Last B " << lastb << endl;
			cout << "Sorted Array : ";
			for(int i=0; i<lasta+lastb; i++)
				cout << output[i] << " ";
			cout << endl << endl;
		}*/
	}
}


int main (int argc, char * argv[]) {
	// Start MPI
	MPI_Init(&argc, &argv);
	
	// Find out my rank!
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	// Find out the number of processes!
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	
	// THE REAL PROGRAM IS HERE
	int n;
	if (my_rank == 0){
		cout << "How many Items? ";
		cin >> n;
	}
	MPI_Bcast(&n, 1,  MPI_INT, 0, MPI_COMM_WORLD);
	int * a = new int [n];
	if (my_rank == 0){
		for(int i=0; i<n; i++){
			a[i] = rand()%500;
			for(int j=0; j<i; j++){
				if (a[i] == a[j])
					i--;
			}
		}
		for(int i=0; i<p; i++)
			MPI_Send(a, n, MPI_INT, i, tag, MPI_COMM_WORLD);
	}
	else{
		MPI_Recv(a, n, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
	}
		
	if(my_rank == 0){
		cout << "Unsorted big array ";
		for(int i=0; i<n; i++)
			cout << a[i] << " ";
		cout << endl << endl;
	}
	if (n%2==0)
		pmerge(&a[0], &a[n/2], n/2, n/2);
	else 
		pmerge(&a[0], &a[n/2], n/2, (n/2)+1);
	
	if(my_rank == 0){
		cout << "Sorted big array ";
		for(int i=0; i<n; i++)
			cout << a[i] << " ";
		cout << endl << endl;
	}
	//}
	// Shut down MPI
	MPI_Finalize();

	return 0;
}