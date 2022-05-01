// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment
//
// mbeltz
#include <iostream>
int main()
{
	int bScore, xScore;
	// Butler score and Xavier score
	
	std::cout << "Welcome to my game score simulation – can Butler win?" << "\n" << "\n";
	std::cout << "Please enter the Butler score: ";
	std::cin >> bScore;
	std::cout << "\n";
	std::cout <<"Please enter the Xavier score: ";
	std::cin >> xScore;
	std::cout << "\n";
	
	if (bScore > xScore)
	{
		std::cout << "Butler wins by " << bScore - xScore << "!"
				<< "\n" << "\n" << "Thank you! Goodbye!";
	}
	
	else
	{
		std::cout << "Come on Butler, you can do it – score " << xScore - bScore + 1 
				<< " or more points to win!" << "\n" << "\n" << "Thank you! Goodbye!"
				<< "\n";
	}
	
	return 0;
}