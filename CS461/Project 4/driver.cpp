#include "Builder.h"
#include "VisitorConcrete.h"

// Dr. Ryan: This brings sadness to my programmer soul...
//Now you know how I feel
using namespace std;

// I promise that the work submitted here is solely my own.
//
// mbeltz
int main ()
{
	Builder tree;
	VisitorConcrete visitor; 
	string input = "";
	cout << "Please enter an equation seporated by spaces: ";
	std::getline(std::cin, input);
	cout << input << endl;
	Node * head = tree.build(input);
	visitor.calculateResult(head);
	cout << "Your answer is: " << visitor.getResult() << endl;
	delete head;
}

