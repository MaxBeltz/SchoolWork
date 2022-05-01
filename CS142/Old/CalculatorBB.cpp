// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment
//
// mbeltz
#include <iostream>
#include <string>
int main()
{
	int num1;
	int num2;
	int answer;
	double answerd;
	std::string operation;	
	
	std::cout << "Hello! Welcome to my calculator. Please enter your operation (Addition, Subtraction, Multiplication, Division, End)" << "\n";
	std::cin >> operation;
	// this is how you comment
	// 4 and 5 can be int num1, num2 as they are the same type 
	// << used for output >> used for input 
	while ( !operation.compare("End") == false)
	{
		if ( !operation.compare("Addition") == true)
		{
			std::cout << "Please enter two numbers to add" << "\n";
			std::cin >> num1;
			std::cin >> num2;
			//or std cin >> num1 >> num2;
			answer = num2 + num1;
			std::cout << "Answer: " << answer << "\n";
			std::cout << "Would you like Addition, Subtraction, Multiplication, Division, or to End)" << "\n";
			std::cin >> operation;
		}
			
		else if ( !operation.compare("Subtraction") == true)
		{	
			std::cout << "Please enter two numbers to subtract" << "\n";
			std::cin >> num1;
			std::cin >> num2;
			answer = num2 - num1;
			std::cout << "Answer: " << answer << "\n";
			std::cout << "Would you like Addition, Subtraction, Multiplication, Division, or to End)" << "\n";
			std::cin >> operation;
		}
		
		else if ( !operation.compare("Multiplication") == true)
		{
			std::cout << "Please enter two numbers to multiply" << "\n";
			std::cin >> num1;
			std::cin >> num2;
			answer = num2 * num1;
			std::cout << "Answer: " << answer << "\n";
			std::cout << "Would you like Addition, Subtraction, Multiplication, Division, or to End)" << "\n";
			std::cin >> operation;
		}
		
		else if ( !operation.compare("Division") == true)
		{
			std::cout << "Please enter two numbers to divide" << "\n";
			std::cin >> num1;
			std::cin >> num2;
			answerd = (double)num2 / (double)num1;
			std::cout << "Answer: " << answerd << "\n";
			std::cout << "Would you like Addition, Subtraction, Multiplication, Division, or to End)" << "\n";
			std::cin >> operation;
		}
		else
		{
			std::cout << "I'm sory, I Don't understand" << "\n";
			std::cout << "Would you like Addition, Subtraction, Multiplication, Division, or to End)" << "\n";
			std::cin >> operation;
		}
	}
	std::cout << "Thank you for using my calculator" << "\n";
	return 0;
}	

