#ifndef NONSTANDARDDECK
#define NONSTANDARDDECK

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
using namespace std;
#include "deckofcards.h"
#include "card.h"

class NonStandardDeck: public Deck {
	private: 
	protected:
	public:
		NonStandardDeck(int size);				//creates a deck of a size of your cjoosing
		NonStandardDeck(string file, bool war);	//creates a deck with a size from the file, war asks if it wants 2n max size
		~NonStandardDeck();						//destroyes cards
		void readCards(string file);			// read in cards from a file
		
		
};

#endif