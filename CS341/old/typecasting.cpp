#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;

int main (){
	//typecasting is the changing of a variable type explicitly
	//this is a dangerous practice and you need to be careful
	
	//since we know now that every variable, class, ets, is really just a memory location
	//all we have to do is change the variable to tell is that something else is there
	//typecasting behaves differently for pointers and non pointers
	
	char c = 'a'; //this has an ASCII valus of 97
	
	cout << c << endl;
	cout << (int) c << endl;
	
	cout << setw(5) << "dec" << setw(5) << "char" << endl;
	for (int x=0; x<256; x++)
		cout << setw(5) << x << setw(5) << (char) x << endl;
	
	//this is different from pointer casting
	//you cant cast whatever to whatever 
	
	//wont work 
	//cout << (ostream) c << endl;
	
	//some of the bigger types work naturally
	cout << (float) c << " " << (double) c << endl;

	//smaller data types have issues
	double d = 12.3
	cout << (int) d << endl;
	
	char * dPtr = &d;
	cout << *dPtr << endl;
	cout << dPtr << setw(12) << *dPtr << endl;
	cout << (int*) dPtr << setw(12) << (* (int*) dPtr) endl;
	
	//useful data types for your project
	uint8_t g; //this means an unsigned int using 8 bits
	uint16_t h; //this means an unsigned int using 16 bits
	uint32_t j; //this means an unsigned int using 32 bits
	uint64_t k; //this means an unsigned int using 64 bits
	
	//how to declare literal values of bionay types
	uint32_t p = 7;
	cout << p << endl;
	uint32_t q = 0b0000111;	//explicitly written bionary
	cout << q << endl;
	p = 0xFFFF;  			//explicitly written Hex
	cout << p << endl;
	
	return 0
}