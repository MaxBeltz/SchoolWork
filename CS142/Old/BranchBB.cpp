// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment
//
// mbeltz
#include <iostream>
#include <string>
#include <stdlib.h> //used for rand
#include <time.h> //used for time
#include <stdio.h> // used for seeding
int main()
{
	int bScore, oScore;
	// Butler score and opponent score the random integer used to determine score
	std::string opponent;
	// Butler's opponent
	int score, who;
	// The random integer used to determine score, the random int used to determine who scored
	int quarter, clock, didthey;
	// How many quarters, time left in the quarter, and did they score in any given second
	char pause;
	// Used to break up outputs
	
	quarter = 1;
	bScore = 0;
	oScore = 0;
	// Initial values
	srand (time(NULL));
	// Seeding
	
	std::cout << "Welcome to my game score simulation – can Butler win?" << "\n" << "\n";
	std::cout << "Who is Butler's opponent? ";
	std::cin >> opponent;
	std::cout << "Welcome to the exciting game between Butler and " << opponent << " We will update you with every score (press enter to continue)" << "\n";
	std::cout << "The current score is Butler: " << bScore << " " << opponent << ": " << oScore << "\n";
	// Shoud correctly list Butler and its previously entered opponent with a score of 0 to 0
	
	while ( quarter < 5 ) //start of simulation
	{
		clock = 720; // 12 minutes each quarter
		std::cout << "\n" << "It is quarter number " << quarter << "\n";
		while ( clock > 0)
		{
			didthey = rand() % 30 + 1; // Random number chosen so there is a 1 in 30 chance on scoring evey second
			if ( (didthey % 25) == 0) // There is a score
			{
				who = rand() % 2 + 1;
					// who = 1 Butler scored, who = 2 opponent scored
				score = rand() % 3 + 1;
					// how many points 1 2 or 3
					
				if (who == 1) //Butler scored
				{
					bScore = bScore + score;
				}
				else if (who == 2) //Opponent scored
				{
					oScore = oScore + score;
				}
				else
				{
					std::cout << "Error on which team scored";
				}
				pause = getchar();
				// Break up output
				if ( (clock % 60) > 9) // showing the clock correctly when less than 10 seconds
				{
					std::cout << "The current score is Butler: " << bScore << " " << opponent << ": " 
							<< oScore << " with " << clock / 60 << ":" << clock % 60 << " on the clock" << "\n";
				}
				else
				{
					std::cout << "The current score is Butler: " << bScore << " " << opponent << ": " 
							<< oScore << " with " << clock / 60 << ":0" << clock % 60 << " on the clock" << "\n";
				}
				
			} // This only runs if there is a score but is checked every second
			else
			{
				// This is intentionally empty as the point scored code should only have a 1 in 30 chance of running
			}
			clock = clock - 1;
		}
		quarter++; // should run 4 times for 4 quarters
	}
	
	std::cout << "That's the buzzer, the game is over ";
	if (bScore > oScore) //Butler wins
	{
		std::cout << "Butler has won by an astounding " << bScore - oScore << " points!" << "\n";
	}
	else if (oScore > bScore) //Butler looses
	{
		std::cout << "Butler has come up short by just " << oScore - bScore << " points!" << "\n";
	}
	else if (oScore == bScore) //tie
	{
		std::cout << "Butler has tied with " << opponent << ". That was anticlimactic." << "\n";
	}
	else
	{
		std::cout << "Error on winning team";
	}
	return 0;
}