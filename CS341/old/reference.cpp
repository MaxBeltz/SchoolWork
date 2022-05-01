#include <iostream>
#include <math.h>
using namespace std;

int main () {
	int x = 6;
	int y = 11;
	int z = 12;
	
	//a reference refers to the address of the variable (an alies)
	int & w = z;
	
	z=23;
	cout << z << endl;
	cout << w << endl;
	cout << endl << endl;

	//zPtr is a pointer, which is a variable that stores a memory address
	int * zPtr;
	zPtr = &z;
	
	cout << zPtr << endl;
	cout << &z << endl;
	cout << &w << endl;

	//another way to create an array
	int * b = new int[10];
	
	int * c = new int;
	
	//you must delete pointers to prevent memory leaks
	//if you use new you must delete
	//you must understande the scope of the variable to delete it 
	delete [] b;
	delete c;
}	