#include "card.h"
string Card::suit[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};
string Card::face[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card(int fa, int su) {
	face_val = fa;
	suit_val = su;
}

Card::Card(){
	face_val = 0;
	suit_val = 0;
}

Card::~Card(){}

string Card::getFace(){
	return face[face_val];
}

string Card::getSuit(){
	return suit[suit_val];
}

string Card::prettyCardName(){
	return getFace() + " of " + getSuit();
}

bool Card::equalFace(Card test){
	return face_val == test.face_val;
}