#ifndef DECK_OF_CARDS
#define DECK_OF_CARDS

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;
#include "card.h"

class Deck {
	private: 
	protected:
		int maxSize;					//the size of the array
		int currentTop;					//the current top of the deck
		Card * cards;					//the array of cards
		int numCards(); 				// returns the number of cards remaining in the deck
	public:
		// Class management
		Deck(); 						//virtual, will not be called
		virtual ~Deck(); 				//not constructed and will not be destroyed
		bool standardFill();			//fills a deck the standard 52 cards
		
		// Key class functionality
		void shuffle(); 				// any sufficiently random sort with at least 3n random swaps is fine
		Card dealCard();				// deal the top card of the deck and remove it from the deck
		bool addCard(Card &);			// append card to deck if there is space, fail otherwise
		bool mergeDecks(Deck *, bool);	// add cards from input to this deck, then empty the input deck. bool for shuffle afterwards (default = false)
		
		// Display functions
		Card displayCard(int);			// displays the ith card of the deck
		bool isEmpty();					// returns whether or not the deck is empty
		void printDeck();				// print a nicely formatted list of the cards in deck order
		Card displayTop();				//displays the top card of the deck
		int cardsRemaining();			//returns the number of cards in the deck (currentTop)
};

#endif