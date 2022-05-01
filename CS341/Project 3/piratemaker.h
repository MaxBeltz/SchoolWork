//Author: Andrew Spores
//Date: 11/2/2021
//you can use generate_portal() in your driver program
//by including this file: #include "piratemaker.h"

#include <fstream>
#include <iostream>

using namespace std;

/*	generate_portal() creates a file named "portal.txt" in the current directory
	and fills it with 1000 pirates.
	feel free to change the implementation for how the pirates are generated
*/

void generate_portal() 
{
	//Minimum and maximum heights of generated pirates
	int min_height = 1;
	int max_height = 15;
	
	//how many pirates to generate
	int num_pirates = 1000;
	
	ofstream writer("portal.txt"); //create portal.txt and load it into our ofstream object
	
	for (int i = 0; i < num_pirates; i++)
	{
		//sets random height between range and writes that pirate to the file
		int random_height = min_height + rand() % max_height;
		writer << "Pirate_" << i << " " << random_height << "\n";
	}
	
	writer.close();
	
	return;
}