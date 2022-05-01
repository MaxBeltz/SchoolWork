#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <string>
#include "NonStandardDeck.h"
#include <fstream>
using namespace std;

NonStandardDeck::NonStandardDeck(int size){
	cards = new Card[size];
	currentTop = -1;
	maxSize = size;
}//created a deck of size not 52

NonStandardDeck::NonStandardDeck(string file, bool war){
	ifstream infile; 
	infile.open(file); 
	int size;
	infile >> size;
	if (war) //the game is war
		maxSize = 2*size;
	else
		maxSize = size;
	cards = new Card[maxSize];
	currentTop = -1;
	readCards(file);
	infile.close();
}

NonStandardDeck::~NonStandardDeck(){
	delete [] cards;
}

void NonStandardDeck::readCards(string file){
	int face = 0;
	int suit = 0;
	//Card insert(0,0);
	ifstream infile; 
	infile.open(file); 
	int size;
	infile >> size;
	for (int i=0; i<size; i++) {
		infile >> suit;
		infile >> face;
		Card insert(face, suit);
		addCard(insert);
	}	
}
