// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment
//
// mbeltz
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class player
{
	private: //Three parts
		std::string firstname;
		std::string lastname;
		int number;
	public:
		void setNumber(int newnumber) //Changes the number or the player
		{
			number = newnumber;
		}
		int getNumber() //Retuns the number
		{
			return number;
		}
		std::string getName() //Returns the name
		{
			return firstname + " " + lastname;
		}
		player (std::string first, std::string last, int num) : firstname("Error"), lastname("Error"), number(999)
		{
			//Constructor shows an error if no input
			firstname = first;
			lastname = last;
			number = num;
		}
		player (void) :  firstname("Error"), lastname("Error"), number(999)
		{
			firstname = "Error";
			lastname = "Error";
			number = 999; 
			//if this is created there is an error
		}
		~player()
		{
			//Empty
		}
};

int main()
{
	std::ifstream inputfile; //File input
	std::string input(""); //Used to determine which file is opened
	std::string line; // used to hold each line
	std::string number; // used to read the number
	std::string fname; // used to read the first name
	std::string lname; // used to read the last name 
	int playernumber; // used as an int version of number
	
	std::cout << "Welcome to Max's Classy Roster Program" << "\n";
	std::cout << "Please enter a file name: ";
	std::cin >> input;
	inputfile.open(input.c_str()); //converts input ro a readable file
	
	if(inputfile.fail())
	{
		std::cout << "Unable to open file " << input << "!" << "\n";
	}
	
	else
	{
		std::cout << "Number         Name\n";
		std::cout << "*******************************\n";

		while (std::getline(inputfile, line, '\n'))
		{
			std::stringstream ss; //stringstream 
			ss.clear(); //clearing the stream
			ss.str(line); //holds each line
			
			std::getline(ss, lname, ' '); //used to find the last name
			std::getline(ss, fname, ' '); //used to find the first name
			std::getline(ss, number, '\n'); //used to find the number
			std::istringstream buffer(number); //used to convert number to an int
			buffer >> playernumber; //final converstion
			
			player myPlayer(fname, lname, playernumber); //creates the object with the given values
			
			if (myPlayer.getNumber() > 9)
			{
				std::cout << "#" << myPlayer.getNumber() << "     " + myPlayer.getName() + "\n";			
			}
			else
			{
				std::cout << "#" << myPlayer.getNumber() << "      " + myPlayer.getName() + "\n";
			}
		}
	}
	
	inputfile.close(); //closing the stream
	std::cout << "Thank you for using my program - good bye!" << "\n";
	
	return 0;
}
















