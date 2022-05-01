// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment
//
// mbeltz
#include <iostream>
#include <string.h>

void reversedWord(char input[], int size);

int main()
{
	char word[100]; // The array that will be swapped
	int pass(0); // The length of the array that will be passed
	char cont = 'x'; // Used to ask if continue
	std::cout << "Welcome to Max's Word Reversal Program!\n";
	std::cout << "Please enter a word less than 100 charecters: ";
	std::cin >> word;
	std::cout << "The word you entered was: " << word << "\n";
	pass = strlen(word);
	reversedWord(word, pass);
	std::cout << "Would you like to continue (Y|N)? ";
	std::cin >> cont;
	while ( cont != 'N') // So you can keep asking
	{
		if (cont == 'Y') // Go again
		{
			std::cout << "Please enter a word less than 100 charecters: ";
			std::cin >> word;
			std::cout << "The word you entered was: " << word << "\n";
			pass = strlen(word);
			reversedWord(word, pass);
			std::cout << "Would you like to continue (Y|N)? ";
			std::cin >> cont;
		}
		
		else // For an Invalid input
		{
			std::cout << "Invalid Input - Please enter 'Y' or 'N': ";
			std::cin >> cont;
		}
	}
	
	std::cout << "Thank you! Goodbye!\n";
	return 0;
}

void reversedWord(char input[], int size)
{
	int actlen = strlen(input); // This will be the unchanging number to compair to
	char dump = 'x'; // Used so there is no loss of data
	char cont = 'x'; // Used to ask if continue
	if (size == -1)
	{
		// Do noting to skip to the acking if they want to go again
		// This can only be reached on an invalid input
	}
	else if ( (actlen - size) < size) //this is for once the two values woud switch places
	{
		dump = input[size-1]; // So we dont loose data
		input[size-1] = input[actlen - size];
		input[actlen - size] = dump;
		size--;
		reversedWord(input, size);
	}
	else
	{
		std::cout << "The word reversed is: " << input << "\n";
	}
}