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
	
	// THE REAL PROGRAM IS HERE
    sprintf(message, "Yo Baby, it's a tripple: %d %d", my_rank, p);
	cout << message << endl;
	
	// Send a message of a certain length and type to prcessor 1
	MPI_Send(message, strlen(message) + 1, MPI_CHAR, 1, tag, MPI_COMM_WORLD);
	
	// Recieve a message of size up to 100 and type MPI_CHAR from process 0
	if(my_rank == 1)
		MPI_Recv(message, 100, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
	
	cout << message << endl;
	
	// Shut down MPI
	MPI_Finalize();

	return 0;
}