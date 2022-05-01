#include <iostream>
#include <string>
using namespace std;

//this tepmlate works for any object that has overloaded &ostream << T
template<typename T>
void printArray(const T * const a, const int size){
		for (int x=0; x < size; x++)
	{
		cout << a[x] << " ";
	}
	cout << endl;
}//template

/*void printArray (const int * const a, const int size){
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

void printArray (const double *a, const int size){
	for (int x=0; x < size; x++)
	{
		cout << a[x] << " ";
	}
	cout << endl;
} //double */

int main(){
	int b[4] = {2,4,6,8};
	string c[4] = {"two", "four", "six", "eight"};
	printArray(b,4);
	printArray(c,4);
	
	return 0;
}
