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
    cout << "My face number is " << my_rank << ", and I am sitting in seat ";
	
	cout << (my_rank/4) +1; //row number
	int seat = my_rank%4; //seat position
	if (seat == 0)
		cout << "A." << endl;
	else if (seat == 1)
		cout << "B." << endl;
	else if (seat == 2)
		cout << "C." << endl;
	else
		cout << "D." << endl;
	/*switch(seat) {
		case 0: cout << "A." <<endl; break;
		case 1: cout << "B." <<endl; break;
		case 2: cout << "C." <<endl; break;
		case 3: cout << "D." <<endl; break;
		
	}*/

	// Shut down MPI
	MPI_Finalize();

	return 0;
}