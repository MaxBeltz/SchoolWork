#ifndef STANDARDDECK
#define STANDARDDECK

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;
#include "card.h"
#include "deckofcards.h"

class standardDeck: public Deck {
	private: 
	protected:
	public:
		standardDeck();
		~standardDeck();
};

#endif