#ifndef CARD
#define CARD

#include <iostream>
#include <string>
using namespace std;

class Card {
	private: 
		int face_val;
		int suit_val;
	public:
		// Class management
		Card(int, int);
		Card();
		~Card();
		static string face[14];
		static string suit[5];
		bool equalFace(Card);
		
		// Display functions
		string getFace();			// returns the face of the card
		string getSuit();			// returns the suit of the card
		string prettyCardName();	// returns a string with the full name of the card, e.g. "Ace of Spades"
};

#endif