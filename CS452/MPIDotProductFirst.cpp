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
    cout << my_rank << endl;
	
	//Know the problem
	
	//srand(time(0));
	srand(1241);
	int n = 300000;
	long int dotproduct = 0;
	int * a = new int[n];
	int * b = new int[n];
	
	if (my_rank == 0){
		for (int x = 0; x < n; x++){
			a[x] = rand() % 8;
			b[x] = rand() % 8;
		}
	}
	
	//Divide the problen in two pieces
	int localn = n/p;
	int * locala = new int[localn];
	int * localb = new int[localn];
	
	//After executing the lines below, locala and localb will have the right stuff in them
	//In otherwords each array will have the block of array a and be that corresponds to the information they should have for their rank
	MPI_Scatter(&a[0], localn, MPI_INT, locala, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(&b[0], localn, MPI_INT, locala, MPI_INT, 0, MPI_COMM_WORLD);

	//Do the local work
	long int localDot = 0;
	for(int x = 0; x < localn; x++)
			localDot += locala[x] * localb[b];
	
	//Collect the results back together
	if (my_rank != 0)
		MPI_Send(&localDot, 1, MPI_LONG, 0, tag, MPI_COMM_WORLD);
	else{
		dotproduct = localDot;
		long int temp;
		for (int x = 1; x < p; x++){
			MPI_Recv(&temp, 1, MPI_LONG, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &status)
			dotproduct += temp;
		}
		cout << dotproduct << endl;
		
		//Check manually 
		dotproduct = 0
		for (int x = 0; x < n; x++)
			dotproduct += a[x] * b[x]
		cout << dotproduct << endl;
	}
	
	// Shut down MPI
	MPI_Finalize();

	return 0;
}