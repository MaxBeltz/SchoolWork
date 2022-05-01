#include <iostream>
#include <string>
using namespace std;

//Summary of Polymorphism
//1) Virtual Member functions
//2) Name overloading -- an entity that shares a name but not the parameters
//3) Operator overloading -- an operator has a different implementation on context

//const as a indintifier/qualifier is used in a million different ways


void printArray (const int * const a, const int size){
	//const in front of the variable type implies that you cannot change the value of the variable in this function 
	//the const in front of the variable of a pointer means you cannot change what a points to
	for (int x=0; x < size; x++)
	{
		cout << a[x] << " ";
	}
	cout << endl;
} //int

void printArray (const string *a, const int size){
	for (int x=0; x < size; x++)
	{
		cout << a[x] << " ";
	}
	cout << endl;
} //string

int main(){
	int b[4] = {2,4,6,8};
	string c[4] = {"two", "four", "six", "eight"};
	printArray(b,4);
	printArray(c,4);
	
	return 0;
}

//Auxilary Notes
//1) if you have a virtual function in a class you must have a virtual destructor as well
//2) Pure virtual function -- a virtual function where you want to require derrived classes to redefine
// 		virtual int area() = 0
//3) A Pure Abstract Class is a class that contains only pure virtual functions
//	--for example if we created a Shape Class, from which Rectange, Sphere, and Triangle inherited, it would make sence for shape to be pure virtual
//4) You cannot creat virtual constructors