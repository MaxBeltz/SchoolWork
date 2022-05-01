#include <iostream>

int funct (int input);

int main()
{
	int input(0);
	
	std::cout << "please enter a value: ";
	std::cin >> input;
	std::cout << "\n\n";
	
	std::cout << "the factorial of your value is: " << funct(input);
	
	return 0;
}

int funct (int input)
{
	if (input <= 1)
	{
		return 1;
	}
	else
	{
		return input * funct(input-1);
	}
	
}