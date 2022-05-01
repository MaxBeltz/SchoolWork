#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

#include "Sort.h"
#include "bubbleSort.h"
#include "InsertionSort.h"

//int array_size = 50;

int main()
{
	int numArray[50];
	int ui = 0, ui2 = 0;
	//Menu
	while(true)
	{
		std::cout << "\n\n1. Load File\n2. Exit Program\nPlease enter your selection: ";
		std::cin >> ui;
		if (ui == 1)
		{
			//Input Stream
			std::ifstream inFile("data.txt");

			//Variable to store the "read in" line
			std::string currentLine;

			//Instance of a stringstream
			std::stringstream converter;

			//Instance of a StringStream
			std::stringstream ss;

			//Integer Variable
			int number;

			//String Variable
			std::string stringNumber;

			//try open the file
			if(inFile.is_open())
			{
				int i = 0;
				while(getline(inFile, currentLine))
				{
					//clear out the stringStream object
					ss.clear();

					//set the init val to empty string
					ss.str("");

					//Load the "current line" into the stringstream obj
					ss.str(currentLine);

					while(getline(ss, stringNumber, ','))
					{
						//Clear out the StringStream object
						converter.clear();

						//set the init val to the empty string
						converter.str("");

						//convert stringNumber into an int
						converter << stringNumber;

						//output the result of conversion into our int
						converter >> number;

						//std::cout << number << std::endl;

						numArray[i] = number;
						i++;
					}
				}

				inFile.close();
			
				std::cout << "\n\nUnsorted Array: ";
				for (int i = 0; i < 50; i++)
				{
					std::cout << numArray[i] << ",";
				}
			}
			else
			{
				std::cout << "Error opening file... Exiting" << std::endl;
				exit(EXIT_FAILURE);
			}

			
			//Second Menu
			while(true)
			{
				std::cout << "\n\n1. Insertion Sort\n2. Bubble Sort\n3. Exit Program\nPlease enter your selection: ";
				std::cin >>ui2;
				if(ui2 == 1)
				{
					// Create insertsort object on heap and run numSort
					Sort * newIsort = new insertSort(numArray, 50);
					newIsort->numSort();
					delete newIsort;
					//break out of the loop to re load the data
					break;
				}
				if(ui2 == 2)
				{
					// Create bubblesort object on heap and run numsort
					Sort * newBsort = new bubbleSort(numArray, 50);
					newBsort->numSort();
					delete newBsort;
					//break out of the loop to reload the data
					break;

				}
				if(ui2 == 3)
				{
					//exit
					std::cout << "Goodbye!" << std::endl;
					exit(0);
				}
			
				else
				{
					//If not int 1-3 ask for valid input
					//std::cout << "Please enter valid input" << std::endl;
					std::cin.clear();
					std::cin.ignore(100, '\n'); 
				}
			}
		}
		if (ui == 2)
		{
			//exit
			std::cout << "Goodbye!" << std::endl;
			exit(0);
		}
		else
		{
			//std::cout << "Please enter valid input" << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n'); 
		}
	}
}
