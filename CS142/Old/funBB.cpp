// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment
//
// mbeltz
#include <iostream>
#include <string>

void getInput(double &first, double &second, bool &correct); //correct will be used to see if they entered a number
double calculateAddition(double first, double second); 
double calculateSubtraction (double first, double second);
double calculateMultiplication (double first, double second);
double calculateDivision (double first, double second);
double calculateExponent (double first, double second);
double calculateRoot (double first, double second);
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
	bool correct = true; //true implies a number was entered, false implies that it wasn't
	std::string menue = "Welcome to my Calculator!\n\n1.\tAddition (x+y)\n2.\tSubtraction (x-y)\n3.\tMultiplication (x*y)\n4.\tDivision (x/y)\n";
	menue = menue + "5.\tExponential (x^y)\n6.\tRoot (x√y)\n7.\tQuit Program \n\nPlease enter your choice ";
	// Used for the menue so its not ugly later
	
	std::cout << menue;
	std::cin >> operation;
	// initial selection
	
	while (operation !=7) 
	{
		getInput(first, second, correct);
		if (correct == false)
		{
			operation = 0;
		}
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
		else if (operation == 5)
		{
			answer = calculateExponent (first, second);
			std::cout << first << " ^ " << second << " = "<< answer << "\n" << "\n";
		}
		else if ((operation == 6) && (first >= 0)) //Root must be greater than zero
		{
			answer = calculateRoot (first, second);
			std::cout << first << " √ " << second << " = "<< answer << "\n" << "\n";
		}
		else if ((operation == 6) && (first < 0)) //Root must be greater than zero
		{
			std::cout << "Invalid input. Cannot have a root less than 0." << "\n";
		}
		else //Everything else
		{
			std::cout << "Invalid input!" << "\n";
		}
		std::cout << menue;
		std::cin >> operation;
	}
	std::cout << "Thank you for using my calculator - goodbye!" << "\n";
}

void getInput(double &first, double &second, bool &correct)
{
	std::cout << "Please enter a value: ";
	std::cin >> first;
	if (std::cin.fail()) //if they entered the wrong type
	{
		std::cin.clear(); //stops the endless looping
		std::cin.ignore(); //ignores the mistake
		first = 0;
		correct = false;
	}
	else		
	{
		std::cout << "Please enter another value: ";
		std::cin >> second;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			second = 1;
			correct = false;
		}
		else
		{
			correct = true; //true because only numbers were entered
		}
	}
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
double calculateExponent (double first, double second)
{
	double calculation = first; //this will be used for the calculations
	while (second > 1)
	{
		calculation = calculation * first;
		second --;
	}
	return calculation;
}
double calculateRoot (double first, double second)
{
	double calculation(0); //this will be used for the calculation
	double scaler(1); //this will be used to scale calculation
	std::cout << "Ran Program" << "\n";
	while (second != calculateExponent(calculation, first) && scaler > .00000000001) 
	{
		//While the calculation to the power of first is not the second that is, while we cannot reverse the root and the second value is to stop from going forever
		if (calculateExponent (calculation, first) < second) //the number is too small
		{
			calculation = calculation + scaler;
		}
		else if (calculateExponent (calculation, first) > second) //the number is too big
		{
			calculation = calculation - scaler; //making calculation smaller to so when it's reaised it is not too big
			scaler = scaler * .1; //used for more percision
			calculation = calculation + scaler; //increasing calculation by 1 decimal point
		}
		else
		{
			//do nothing
		}
	}
	std::cout << "Ran end" << "\n";
	return calculation;
}













