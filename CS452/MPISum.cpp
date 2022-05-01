#include <iostream>
#include <stdio.h>
#include <string.h>
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
	
	// Steps for solving an embarrassingly parallel problem
	// 1. Know the problem
	int n = 300000;
	long int sum = 0;
	
	// 2. Break the problem into pieces
	int local_start = (n/p) * my_rank;
	
	// 3. Each process does it's own local work
	long int local_sum = 0;
	for(int x = local_start; x < (local_start + (n/p)); x++;;)
		local_sum += x;
	
	// 4. Combine the local sums
	// The processor that is in charge is called the overseer. By convention this is processor 0
	if(my_rank != 0)
		MPI_Send(&local_sum, 1, MPI_LONG, 0, tag, MPI_COMM_WORLD);
	else{
		sum = local_sum;
		long temp;
		for(int x = 1; x < p; x++){
			MPI_Recev(&temp, 1, MPI_LONG, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &status)
			sum += temp;
		}
		cout << sum << endl;
	}

	// Shut down MPI
	MPI_Finalize();

	return 0;
}