// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment
//
// mbeltz
#include <iostream>
#include <string>

void getInput(double &first, double &second);
double calculateAddition(double first, double second); 
double calculateSubtraction (double first, double second);
double calculateMultiplication (double first, double second);
double calculateDivision (double first, double second);
// all of the functions that will be used throught the program
// all the variables are named first and second as you should be able to use any 2 numbers on any function (except devide by 0)

int main()
{
	double first(0), second(0);
	// The two variables used for calculation
	int operation(0);
	// Used to select the operation used
	double answer(0);
	// The variable used for the answer to output
	std::string menue = "1.\tAddition (x+y)\n2.\tSubtraction (x-y)\n3.\tMultiplication (x*y)\n4.\tDivision (x/y)\n5.\tQuit Program \n\nPlease enter your choice ";
	// Used for the menue so its not ugly later
	
	std::cout << "Welcome to my Calculator!\n\n" << menue;
	std::cin >> operation;
	// initial selection
	
	while (operation != 5)
	{
		getInput(first, second);
		if (operation == 1) //Addition
		{
			answer = calculateAddition(first, second);
			std::cout << first << " + " << second << " = "<< answer << "\n" << "\n";
		}
		else if (operation == 2) //Subtraction
		{
			answer = calculateSubtraction(first, second);
			std::cout << first << " - " << second << " = "<< answer << "\n" << "\n";
		}
		else if (operation == 3) //Multiplication
		{
			answer = calculateMultiplication(first, second);
			std::cout << first << " * " << second << " = "<< answer << "\n" << "\n";
		}
		else if ((operation == 4) && (second != 0)) //Division with an acceptible denominatior
		{
			answer = calculateDivision(first, second);
			std::cout << first << " / " << second << " = "<< answer << "\n" << "\n";
		}
		else if ((operation == 4) && (second == 0)) //Division by zero
		{
			std::cout << "Invalid input. The denominator cannot be 0" << "\n" << "\n";
		}
		else //Everything else
		{
			std::cout << "Invalid input" << "\n";
		}
		std::cout << menue;
		std::cin >> operation;
	}
	std::cout << "Thank you for using my calculator - goodbye!" << "\n";
}

void getInput(double &first, double &second)
{
	std::cout << "Please enter a value: ";
	std::cin >> first;
	std::cout << "Please enter another value: ";
	std::cin >> second;
}

double calculateAddition(double first, double second)
{
	return (first + second);
}

double calculateSubtraction (double first, double second)
{
	return (first - second);
}

double calculateMultiplication (double first, double second)
{
	return (first * second);
}

double calculateDivision (double first, double second)
{
	return (first / second);
}












