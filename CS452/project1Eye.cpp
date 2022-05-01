#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "mpi.h" // message passing interface
#include <string>
#include <fstream>
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
    ifstream myFile;
	myFile.open("readable.txt");
	string input = "";
	int charLen = 0;
	int localn = 0;
	
	int * finalCount = new int [26];
	for (int i = 0; i < 26; i++)
		finalCount[i] = 0;
	
	int * charCount = new int [26];
	for (int i = 0; i < 26; i++)
		charCount[i] = 0;
		
	if(myFile.is_open()){
		
		if (my_rank == 0){
			myFile >> input;
			charLen = input.length();
			localn = charLen/p;
		}
		MPI_Bcast(&charLen, 1, MPI_INT, 0, MPI_COMM_WORLD);
		MPI_Bcast(&localn, 1, MPI_INT, 0, MPI_COMM_WORLD);
		char * letters = new char[charLen];
		if (my_rank == 0){
			for (int i = 0; i < charLen; i++)
				letters[i] = input[i];
			//for (int i = 0; i < charLen; i++)
				//cout << letters[i];
			//cout << endl;
		}
		
		char * localChar = new char[localn];
		
		MPI_Scatter(&letters[0], localn, MPI_CHAR, localChar, localn, MPI_CHAR, 0, MPI_COMM_WORLD);
		

		//for(int i = 0; i < localn; i++)
			//cout << localChar[i];
		//cout << endl;
		
		for (int i = 0; i < localn; i++)
			charCount[(int)localChar[i] - (int)'a']++;
		
		//for(int i = 0; i < 26; i++)
			//cout << charCount[i];
		//cout << endl;
		
		for (int i = 0; i <26; i++)
			MPI_Reduce(&charCount[i], &finalCount[i], 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
		
		if (my_rank == 0){
			for(int i = 0; i < 26; i++)
				cout << " number of " << char(97 + i) << ":" << finalCount[i] << endl;
			//cout << endl;
		}
	}

	// Shut down MPI
	MPI_Finalize();

	return 0;
}



