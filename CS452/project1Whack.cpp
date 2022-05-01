#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "mpi.h" // message passing interface
using namespace std;

// New compile and run commands for MPI!
// mpicxx -o blah file.cpp
// mpirun -q -np 32 blah

int main (int argc, char * argv[]) {

	int my_rank;			// my CPU number for this process
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
    srand(7191);
	int n = 100; //Note you can change this value to whatever you choose
	int * numbers = new int[n];
	int localn = n/p;
	int * localNumbers = new int[localn];
	int * finalComp = new int [localn];
	int finMax = 0;
	
	if (my_rank == 0){
		for (int x = 0; x < n; x++)
			numbers[x] = rand() % 1000;
	}
	
	MPI_Scatter(&numbers[0], localn, MPI_INT, localNumbers, localn, MPI_INT, 0, MPI_COMM_WORLD);
	
	int localMax = localNumbers[0];
	for (int i = 1; i < localn; i++){
		if (localNumbers[i] > localMax)
			localMax = localNumbers[i];
	}
	cout << "the maximum for process " << my_rank << " is " << localMax << endl;
	
	MPI_Gather(&localMax, 1, MPI_INT, finalComp, 1, MPI_INT, 0, MPI_COMM_WORLD);
		
	if (my_rank == 0){
		for (int i = 0; i < localn; i++){
			if (finalComp[i] > finMax)
				finMax = finalComp[i];
		}
		cout << "the overall Maximum is " << finMax << endl;
	}
	
	//delete [] numbers;
	//delete [] localNumbers;
	//delete [] finalComp;
	
	// Shut down MPI
	MPI_Finalize();

	return 0;
}