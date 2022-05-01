#include <iostream>

int main()
{	
	int input(0);
	
	std::cout << "Input" << "\n";
	std::cin >> input;
	
	std::cout << "Address of input: " << &input << "\n";
	std::cout << "Value of input by pointer: " << *input << "\n"; 
	
	return 0;
}