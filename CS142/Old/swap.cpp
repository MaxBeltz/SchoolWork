#include <iostream>
#include <string>
void swap(std::string& first, std::string& second);

int main ()
{
	std::string firstString, secondString;
	std::cout << "Please enter the first Name: ";
	std::cin >> firstString;
	std::cout << "\n" << "Please enter the last Name: ";
	std::cin >> secondString;
	std::cout << "\n" << "Your numbers are : " << firstString << " and " << secondString;
	swap(firstString, secondString);
	std::cout << "\n" << "Your numbers swapped are: " << firstString << " and " << secondString;
	
	return 0;
	
}




void swap (std::string& first, std::string& second)
{
	std::string dump = first;
	first = second;
	second = dump;
}