#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <string>
#include "standardDeck.h"
using namespace std;


standardDeck::standardDeck(){
	cards = new Card[52];
	currentTop = -1;
	maxSize = 52;
}//creates a deck of standerd size 52

standardDeck::~standardDeck(){
	delete [] cards;
}