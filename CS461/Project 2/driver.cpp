#include "Array.h"
#include "Fixed_Array.h"
#include "Dynamic_Array.h"
#include "Stack.h"
#include "Queue.h"

#include <iostream>
#include <stdexcept>
#include <cstdlib>

using namespace std;

// I promise that the work submitted here is solely my own.
//
// mbeltz
int main ()
{

	Dynamic_Array <char> noImp;
	cout << "Default constructor" << endl;
	cout << "Current size: " << noImp.size() << endl << endl << endl; 
	
	Dynamic_Array <char>  len(10);
	cout << "Given Length" << endl;
	cout << "Current size: " << len.size() << endl << endl << endl; 
	
	Dynamic_Array <char>  fil('x');
	cout << "Given Length" << endl;
	cout << "Current size: " << fil.size() << endl; 
	for(int i = 0; i<fil.size(); i++)
		cout << fil[i] << " ";
	cout << endl << endl;
	
	const Dynamic_Array <char> confil('y');
	cout << "Given Length const" << endl;
	cout << "Current size: " << confil.size() << endl; 
	for(int i = 0; i<confil.size(); i++)
		cout << confil[i] << " ";
	cout << endl << endl;
	
	Dynamic_Array <char> copied(confil);
	cout << "Copied" << endl;
	cout << "Current size: " << copied.size() << endl; 
	for(int i = 0; i<copied.size(); i++)
		cout << copied[i] << " ";
	cout << endl << endl;
	
	cout << "Get and Set" << endl;
	cout << "Position 3 of fil: " << fil.get(3) << endl;
	cout << "Set Position 3 of fil to r" << endl;
	fil.set(3,'r');
	cout << "New Position 3 of fil: " << fil.get(3) << endl << endl;
	
	cout << "Testing == on confil and copied" << endl;
	if(confil == copied)
		cout << "Equal" << endl;
	cout << endl << endl;
	
	cout << "Testing != on confil and fil" << endl;
	if(confil != fil)
		cout << "Not Equal" << endl;
	cout << endl << endl;
	
	cout << "Testing both finds" << endl;
	cout << fil.find('r') << endl;
	cout << fil.find('r',1) << endl;
	
	Dynamic_Array <char> fil2('s');
	cout << "Testing = on fil2 and fil" << endl;
	for(int i = 0; i<fil2.size(); i++)
		cout << fil2[i] << " ";
	cout << endl;
		cout << "Setting equal" << endl;
	fil2 = fil;
	for(int i = 0; i<fil2.size(); i++)
		cout << fil2[i] << " ";
	cout << endl << endl;
	
	cout << "Testing self equal with fil" << endl;
	fil = fil;
	for(int i = 0; i<fil2.size(); i++)
		cout << fil2[i] << " ";
	cout << endl;
	if(fil == fil)
		cout << "Equal" << endl;
	cout << endl << endl;
	
	Queue <char> def;
	cout << "Default constructor" << endl;
	cout << "Size: " << def.size() << " Empty: " << def.is_empty() << endl << endl << endl; 
	
	cout << "enqueue" << endl;
	def.enqueue('q');
	def.enqueue('q');
	def.enqueue('q');
	cout << "Size: " << def.size() << " Empty: " << def.is_empty() << endl;
	
	Queue <char> copy(def);
	cout << "Copy constructor" << endl;
	cout << "Size: " << copy.size() << " Empty: " << copy.is_empty() << endl; 
	cout << "enqueue" << endl;
	copy.enqueue('q');
	cout << "Size: " << copy.size() << " Empty: " << copy.is_empty() << endl;
	cout << "dequeue" << endl;
	copy.dequeue();
	cout << "Size: " << copy.size() << " Empty: " << copy.is_empty() << endl << endl << endl << endl;
	
	cout << "clear" << endl;
	copy.clear();
	cout << "Size: " << copy.size() << " Empty: " << copy.is_empty() << endl; 
	
	Stack <char> Sdef;
	cout << "Default constructor" << endl;
	cout << "Size: " << Sdef.size() << " Empty: " << Sdef.is_empty() << endl << endl << endl; 
	
	cout << "enqueue" << endl;
	Sdef.push('q');
	Sdef.push('q');
	Sdef.push('q');
	cout << "Size: " << Sdef.size() << " Empty: " << Sdef.is_empty() << " Top: " << Sdef.top() << endl;
	
	Stack <char> Scopy(Sdef);
	cout << "Copy constructor" << endl;
	cout << "Size: " << Scopy.size() << " Empty: " << Scopy.is_empty() << endl; 
	cout << "enqueue" << endl;
	Scopy.push('q');
	cout << "Size: " << Scopy.size() << " Empty: " << Scopy.is_empty() << endl;
	cout << "dequeue" << endl;
	Scopy.pop();
	cout << "Size: " << Scopy.size() << " Empty: " << Scopy.is_empty() << endl << endl << endl << endl;
	
	cout << "clear" << endl;
	Scopy.clear();
	cout << "Size: " << Scopy.size() << " Empty: " << Scopy.is_empty() << endl; 
	
	
	return 0;
}
