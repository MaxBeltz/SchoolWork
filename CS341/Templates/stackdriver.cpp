#include <iostream>
using namespace std;

#include "stacktemplated.h"
int main(){
	Stack<int> intStack();
	
	int intStuff = 2
	
	while (intStack.push(intStuff)){
		cout << intStuff << endl;
		intStuff += 2;
	}
	
	cout << "Stack should be full here" << intStack.isFull() << endl;
	
	while (intStack.pop(intStuff))
		cout << intStuff << endl;
	
		cout << "Stack should be empty here" << intStack.isEmpty() << endl;
}
	