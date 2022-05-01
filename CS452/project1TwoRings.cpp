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
    char * ring1 = message;
	sprintf(ring1, "Holders of the one true ring: ");
	sprintf(ring1 + strlen(ring1), "%d ", my_rank);
	char * ring2 = message;
	sprintf(ring2, "Holders of the two true ring: ");
	sprintf(ring2 + strlen(ring2), "%d ", my_rank);


	if (my_rank == 0) {
		MPI_Send(ring1, strlen(ring1) + 1, MPI_CHAR, 2, tag, MPI_COMM_WORLD);
		MPI_Recv(ring1, 100, MPI_CHAR, p - 2, tag, MPI_COMM_WORLD, &status);
		cout << "The one true ring has returned home ro me, process " << my_rank << endl;
		cout << ring1 << endl;
	}
	else if (my_rank == 1) {
		MPI_Send(ring1, strlen(ring1) + 1, MPI_CHAR, 3, tag, MPI_COMM_WORLD);
		MPI_Recv(ring1, 100, MPI_CHAR, p - 1, tag, MPI_COMM_WORLD, &status);
		cout << "The two true ring has returned home ro me, process " << my_rank << endl;
		cout << ring1 << endl;
	}
	else {
		MPI_Recv(ring1, 100, MPI_CHAR, my_rank - 2, tag, MPI_COMM_WORLD, &status);
		sprintf(ring1 + strlen(ring1), "%d ", my_rank);		
		MPI_Send(ring1, strlen(ring1) + 1, MPI_CHAR, (my_rank + 2) % p, tag, MPI_COMM_WORLD);
	}

	
	// Shut down MPI
	MPI_Finalize();

	return 0;
}