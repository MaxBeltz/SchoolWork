// I promise that the work submitted here is solely my own.
//
// mbeltz

#include "Array.h"
#include <iostream>

using namespace std;

int main(){
	/*Array noImp;
	cout << "Default constructor" << endl;
	cout << "Current size: " << noImp.size()<< " Max Size: " << noImp.max_size() << endl << endl << endl; 
	
	Array len(10);
	cout << "Given Length" << endl;
	cout << "Current size: " << len.size()<< " Max Size: " << len.max_size() << endl << endl << endl; 
	
	Array fil(7,'x');
	cout << "Given Length" << endl;
	cout << "Current size: " << fil.size()<< " Max Size: " << fil.max_size() << endl; 
	for(int i = 0; i<fil.size(); i++)
		cout << fil[i] << " ";
	cout << endl << endl;
	
	const Array confil(11,'y');
	cout << "Given Length const" << endl;
	cout << "Current size: " << confil.size()<< " Max Size: " << confil.max_size() << endl; 
	for(int i = 0; i<confil.size(); i++)
		cout << confil[i] << " ";
	cout << endl << endl;
	
	Array copied(confil);
	cout << "Copied" << endl;
	cout << "Current size: " << copied.size()<< " Max Size: " << copied.max_size() << endl; 
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
	
	Array fil2(9,'s');
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
	
	
	cout << "Testing both Resizes with Fills usinf fil" << endl;
	cout << "Current size: " << fil.size()<< " Max Size: " << fil.max_size() << endl; 
	for(int i = 0; i<fil.size(); i++)
		cout << fil[i] << " ";
	cout << endl;
	fil.resize(10);
	fil.fill('t');
	cout << "Current size: " << fil.size()<< " Max Size: " << fil.max_size() << endl; 
	for(int i = 0; i<fil.size(); i++)
		cout << fil[i] << " ";
	cout << endl;
	fil.resize(11);
	fil.fill('i');
	cout << "Current size: " << fil.size()<< " Max Size: " << fil.max_size() << endl; 
	for(int i = 0; i<fil.size(); i++)
		cout << fil[i] << " ";
	cout << endl;*/
	
	Array Test(7, 'X');
	cout << "Nominal" << endl;
	cout << "Using Brackets: " << Test[3] << endl;
	cout << "Using Get: " << Test.get(3) << endl;
	
	cout << endl << "Minimal" << endl;
	cout << "Using Brackets: " << Test[0] << endl;
	cout << "Using Get: " << Test.get(0) << endl;
	
	cout << endl << "Below Minimal" << endl;
	cout << "Using Brackets: " << Test[1] << endl;
	cout << "Using Get: " << Test.get(1) << endl;
	
	cout << endl << "Below Maximum" << endl;
	cout << "Using Brackets: " << Test[5] << endl;
	cout << "Using Get: " << Test.get(5) << endl;
	
	cout << endl << "Maximum" << endl;
	cout << "Using Brackets: " << Test[6] << endl;
	cout << "Using Get: " << Test.get(6) << endl;
	
	//cout << endl << "Above Maximum" << endl;
	//cout << "Using Brackets: " << Test[7] << endl;
	//cout << "Using Get: "<< Test.get(7) << endl;
	
	cout << endl << "Below Minimum" << endl;
	//cout << "Using Brackets: " << Test[-1] << endl;
	cout << "Using Get: " << Test.get(-1) << endl;
	
	
	return 0;
}