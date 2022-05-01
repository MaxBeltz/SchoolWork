#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include "mpi.h" // message passing interface
#include <cstdlib>
#include <math.h>
using namespace std;

 //New compile and run commands for MPI!
 //mpicxx -o blah file.cpp
 //mpirun -q -np 32 blah

void mergesort (int * a, int first, int last);
void smerge(int * a, int * b, int lasta, int lastb, int * output = NULL);
int ranks(int * a, int first, int last, int valToFind);
void pmerge(int * a, int * b, int lasta, int lastb, int * output = NULL);

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

int ranks(int * a, int first, int last, int valToFind){
	int mid = (first + last)/2;
	int curRank = 0;
	if(first+1 == last){
		if (valToFind > a[last])
			return (last+1);
		else if (valToFind > a[first])
			return last;
		else 
			return first;
	}
	else if(valToFind > a[mid])
		curRank = ranks(a, mid, last, valToFind);
	else if(valToFind < a[mid])
		curRank = ranks(a, first, mid, valToFind);
	else
		curRank = mid-1;
	return curRank;	
}

void pmerge(int * a, int * b, int lasta, int lastb, int * output){
	
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
	

	int n = 16;
	int localn = n/p; 
	/*if (my_rank == 0){
		cout << "How many items?: ";
		cin >> n; //user determines list size
		MPI_Bcast(n, 1, MPI_INT, 0, MPI_COMM_WORLD); 
	}*/
	int * a = new int [2*n];
	int * aRank = new int[n];
	int * b = new int [n];
	int * bRank = new int[n];
	int * c = new int [2*n];
	int * localaRank = new int [localn];
	int * localbRank = new int [localn];
	int log = log2(n);
	int inc = (n/log);
	int * aFocal = new int[inc];
	int * aShapes = new int [2*inc];
	int * bShapes = new int [2*inc];
	int * bFocal = new int[inc];
	int * localaFocal = new int [localn/inc];
	int * localbFocal = new int [localn/inc];
	
	cout << "Log of n : " << log2(n) << " Inc " << inc <<endl;
	

	if (my_rank == 0){ //will only be run by the origional array
		for (int i=0; i<2*n; i++){//fills the list
			a[i] = (rand()%100);
			for(int j=0; j<i; j++){
				if(a[i] == a[j])
					i--;
			}
		}
			
		cout << endl;
		b = &a[n];
		/*for (int i=0; i<n; i++){//fills the list
			b[i] = (rand()%100);
			for(int j=0; j<n; j++){
				if(b[i] == a[j])
					i--;*/
			//}
		//}
		cout << "The Unsorted List A: ";
		for (int i=0; i<2*n; i++)//outputs the unsorted array
			cout << a[i] << " ";
		cout << endl;
		cout << "The Unsorted List B: ";
		for (int i=0; i<n; i++) //outputs the unsorted array
			cout << b[i] << " ";
		cout << endl << endl << endl; //adds space
		mergesort(a,0,n-1);
		mergesort(b,0,n-1);
		for(int i=1; i<p; i++){
			MPI_Send(a, n, MPI_INT, i, tag, MPI_COMM_WORLD);
			MPI_Send(b, n, MPI_INT, i, tag, MPI_COMM_WORLD);
		}
	}
	else{
			MPI_Recv(a, n, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
			MPI_Recv(b, n, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
	}
	
	for (int i=my_rank; i<n; i = i+=p*log){
		localaFocal[i/p*log] = ranks(b,0,n-1, a[i]);
		localbFocal[i/p*log] = ranks(a,0,n-1, b[i]);
	}
	
	if (my_rank != 0){
		MPI_Send(localaFocal, n%(p*log)+((n-p*log)/log*my_rank), MPI_INT, 0, tag, MPI_COMM_WORLD);
		MPI_Send(localbFocal, localn/inc, MPI_INT, 0, tag, MPI_COMM_WORLD);
		MPI_Recv(aFocal, inc, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
		MPI_Recv(bFocal, inc, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
	}
	
	else{
		for(int i=0; i<localn; i++){
			aFocal[i] = localaFocal[i];
			bFocal[i] = localbFocal[i];
			aShapes[i] = localbFocal[i];
			bShapes[i] = localaFocal[i];
		}
		for(int i=1; i<p; i++){
			MPI_Recv(localaFocal, localn/inc, MPI_INT, i, tag, MPI_COMM_WORLD, &status);
			MPI_Recv(localbFocal, localn/inc, MPI_INT, i, tag, MPI_COMM_WORLD, &status);
			for(int j=0; j<localn/inc; j++){
				aFocal[j+localn/inc*i] = localaFocal[j];
				bFocal[j+localn/inc*i] = localbFocal[j];
				aShapes[j+localn/inc*i] = localbFocal[j];
				bShapes[j+localn/inc*i] = localaFocal[j];
			}
		}
		for(int i=0; i<inc; i++){
			aShapes[i+inc] = inc*i+1;
			bShapes[i+inc] = inc*i+1;
		}
		for (int i=0; i<p; i++){
			MPI_Send(aFocal, inc, MPI_INT, i, tag, MPI_COMM_WORLD);
			MPI_Send(bFocal, inc, MPI_INT, i, tag, MPI_COMM_WORLD);
		}
	}
	
	if (my_rank == 0){
		cout << "My Rank: " << my_rank << " The Sorted List A: ";
		for (int i=0; i<n; i++) //prints the sorted array
				cout << a[i] << " ";
		cout << endl;
		cout << "My Rank: " << my_rank << " The Sorted List B: ";
		for (int i=0; i<n; i++) //prints the sorted array
				cout << b[i] << " ";
		cout << endl << endl;
	}
	
	if (my_rank == 0){
		cout << "The ranks of A compaired to B: ";
		for (int i=0; i< inc; i++)
			cout << aFocal[i] << " ";
		cout << endl;
		cout << "The ranks of B compaired to A: ";
		for (int i=0; i< inc; i++)
			cout << bFocal[i] << " ";
		cout << endl << endl;
		mergesort(aShapes, 0, 2*inc-1);
		mergesort(bShapes, 0, 2*inc-1);
		cout << "Gupta method list A: ";
		for (int i=0; i<2*inc; i++)
			cout << aShapes[i] << " ";
		cout << endl << endl;
		cout << "Gupta method list B: ";
		for (int i=0; i<2*inc; i++)
			cout << bShapes[i] << " ";
		cout << endl << endl;
	}
	
	if (my_rank == 0){
		for (int i=0; i<inc; i++){
			c[aFocal[i] + i*inc] = a[i*inc];
			c[bFocal[i] + i*inc] = b[i*inc];
		}
		//for(int i=0; i<2*n; i++)
			//cout << c[i] << " ";
		//cout << endl;
		bool isAfocal = false;
		bool isBfocal = false;
		int currentAinc = 0;
		int currentAFocal = 0;
		int currentBinc = 0; 
		int currentBFocal = 0;
		int aStarting = 0;
		int bStarting = 0;
		int aFinal = 0; 
		int bFinal = 0;
		int cPos = 0;
		for(int i=0; i<2*inc-1; i++){
			cout << "A Start " << aShapes[i] << " B Start " << bShapes[i] << endl;
			cout << "A End " <<  aShapes[i+1] << " B End " << bShapes[i+1] << endl;
			cout << "C position " << aShapes[i]+bShapes[i]+1 << endl; 
			smerge(&a[aShapes[i]], &b[bShapes[i]], 
				aShapes[i+1]-(aShapes[i]), bShapes[i+1]-(bShapes[i]),
				&c[aShapes[i]+bShapes[i]]);
			//for(int i=0; i<2*n; i++)
				//cout << c[i] << " ";
			//cout << endl;
		}
		//cout << "A Start " << aShapes[2*inc-1] << " B Start " << bShapes[2*inc-1] << endl;
		//cout << "A End " <<  n-aShapes[2*inc-1] << " B End " << n-bShapes[2*inc-1] << endl;
		//cout << "C position " << aShapes[2*inc-1]+bShapes[2*inc-1] << endl; 
		smerge(&a[aShapes[2*inc-1]], &b[bShapes[2*inc-1]], 
			n-aShapes[2*inc-1], n-bShapes[2*inc-1], &c[aShapes[2*inc-1]+bShapes[2*inc-1]]);
		//for(int i=0; i<2*n; i++)
			//cout << c[i] << " ";
		//cout << endl;
		cout << "Sorted List C: ";
		for(int i=0; i<2*n; i++)
			cout << c[i] << " ";
		cout << endl;
	}
	//	
	// Shut down MPI
	MPI_Finalize();

	return 0;
}