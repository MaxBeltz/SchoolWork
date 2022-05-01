#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <string>
#include "deckofcards.h"
using namespace std;

Deck::Deck(){
}

Deck::~Deck(){
}

int Deck::numCards(){
	return currentTop +1; 
}

Card Deck::displayCard(int position){
	Card tempCard;
	if (position > currentTop || position < 0) //invalid input
		return tempCard;
	return cards[position];
}

Card Deck::displayTop(){
	Card tempCard;
	if (isEmpty())
		return tempCard;
	return cards[currentTop];
}

bool Deck::isEmpty(){
	return !(currentTop > -1);
}

void Deck::printDeck(){
	for(int i = currentTop; i >= 0; i--){
		cout << cards[i].prettyCardName() << endl;
	}
}

bool Deck::addCard(Card & newCard){
	//cout << currentTop << " " << maxSize << endl;
	if (currentTop == maxSize) //deck is full
		return false;
	currentTop++;
	cards[currentTop] = newCard;
	return true;
}

Card Deck::dealCard(){
	Card deltCard;
	if (currentTop >= 0)
		deltCard = cards[currentTop--];
	return deltCard;
}

void Deck::shuffle(){
	int card1 = 0;
	int card2 = 0;
	Card tempCard;
	for(int i = 0; i<3*currentTop+1; i++) //takes two random numbers and switches them
	{
		card1 = rand() % (currentTop+1);
		card2 = rand() % (currentTop+1);
		while (card1 == card2)
			card2 = rand() % (currentTop+1);
		tempCard = cards[card1];
		cards[card1] = cards[card2];
		cards[card2] = tempCard;
	}
}

bool Deck::mergeDecks(Deck * newDeck, bool shuf){
	if(currentTop + newDeck->currentTop > maxSize)
		return false;
	Card tempCard;
	while(newDeck->currentTop >=0){
		tempCard = newDeck->dealCard();
		addCard(tempCard);
	}
	if(shuf)
		shuffle();
	return true;
}

bool Deck::standardFill(){ //fills a deck of any size with a standard 52 cards
	//cout << "7" << endl;
	if (maxSize < 52 && currentTop == -1)
		return false;
	for (int i=1; i < 5; i++){
		//cout << i;
		for (int j=1; j < 14; j++){
			//cout << j << endl;
			Card CToAdd(j, i);
			addCard(CToAdd);		
		}
	}
	return true; 
}

int Deck::cardsRemaining(){
	return (currentTop + 1);
}