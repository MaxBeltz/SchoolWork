// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment
//
// mbeltz
#include <iostream>
int main()
{
	int num1;
	int num2;
	int answer;
	
	// this is how you comment
	// 4 and 5 can be int num1, num2 as they are the same type 
	// << used for output >> used for input 
	
			std::cout << "Please enter two numbers to add" << "\n";
			std::cin >> num1;
			std::cin >> num2;
			//or std cin >> num1 >> num2;
			answer = num2 + num1;
			std::cout << "Answer: " << answer << "\n";
				
			std::cout << "Please enter two numbers to subtract" << "\n";
			std::cin >> num1;
			std::cin >> num2;
			answer = num2 - num1;
			std::cout << "Answer: " << answer << "\n";
		
			std::cout << "Please enter two numbers to multiply" << "\n";
			std::cin >> num1;
			std::cin >> num2;
			answer = num2 * num1;
			std::cout << "Answer: " << answer << "\n";
		
			std::cout << "Please enter two numbers to divide" << "\n";
			std::cin >> num1;
			std::cin >> num2;
			answer = num2 / num1;
			std::cout << "Answer: " << answer << "\n";
		
	std::cout << "Thank you for using my calculator" << "\n";
	return 0;
}	

