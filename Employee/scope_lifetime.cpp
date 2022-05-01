#include <iostream>
#include <iomanip>
#include "employee.h"

int main() {
	//scope is the region or section of code where you can access the code
	//this is the standard thin that has always been understood about how long var last
	
	//lifetime of a variable is the duration fro which a variable is alive
	//alive means when a variable is in a valid state
	
	{
	//x is a local variable that die when this scope ends
	//the lifetime of a local variable is its scope
	int x = 12;
	}
	
	//lifetime does not have to equal scope
	//examples: var created on the heap 
	//data members inside a class
	//static variables both in classes and functions
	
	Employee dan;
	bob.setName("Dan", "The Man")
	Employee fran;
	fran.setName("Fran", "The Plan")
	
	{
		Employee doomedtodie;
		cout << "Count inside the scope " << doomedtodie.getCount() << endl;
		
	}
	bob.printinfo();
	cout << "Count outside the scope " << dan.getCount() << endl;
	
	
}