#include "standardDeck.h"
#include "NonStandardDeck.h"
#include <iostream>
using namespace std;

bool warStandard(int & p1Score, int & p2Score, int & battlefield)
{
	NonStandardDeck player1(104);
	NonStandardDeck player2(104);
	NonStandardDeck discardPile(104);
	player1.standardFill();
	player2.standardFill();
	player1.shuffle();
	player2.shuffle();
	Card nextCard;
	int rounds = 0;
	while(!(player1.isEmpty()) && !(player2.isEmpty()) && rounds < 1000){
		nextCard = player1.dealCard();
		if(nextCard.equalFace(discardPile.displayTop())){
			discardPile.addCard(nextCard);
			player1.mergeDecks(&discardPile, true);
		}
		else
			discardPile.addCard(nextCard);
		nextCard = player2.dealCard();
		if(nextCard.equalFace(discardPile.displayTop())){
			discardPile.addCard(nextCard);
			player2.mergeDecks(&discardPile, true);
		}
		else
			discardPile.addCard(nextCard);
		rounds++;
	}
	p1Score += player1.cardsRemaining();
	p2Score += player2.cardsRemaining();
	battlefield += discardPile.cardsRemaining();
	if (rounds == 1000)
		return player2.cardsRemaining() >= player1.cardsRemaining();
	if (player1.isEmpty())
		return true;
	return false;
	
}

void victory (int p1Wins, int p2Wins){ //determines the winner
	if (p1Wins > p2Wins)
		cout << "Player 1 wins with " << p1Wins << " wins" << endl;
	else if (p2Wins > p1Wins)
		cout << "Player 2 wins with " << p2Wins << " wins" << endl;
	else
		cout << "Both players tied with 50 wins esch... lame" << endl;
}

void scores(int p1Score, int p2Score, int battlefield){ //determines the average scores
	p1Score = p1Score/100;
	p2Score = p2Score/100;
	battlefield = battlefield/100;
	
	cout << "Average Player 1 Score: " << p1Score << endl;
	cout << "Average Player 2 Score: " << p2Score << endl;
	cout << "Average number of cards remaining in the battlefield: " << battlefield << endl;
}

int main(){
	srand (time(0));
	int p1Wins = 0;
	int p2Wins = 0;
	int p1Score = 0;
	int p2Score = 0;
	int battlefield = 0;
	bool winner;
	for (int i = 0; i < 100; i++){
		winner = warStandard(p1Score, p2Score, battlefield);
		if(winner)
			p2Wins++;
		else
			p1Wins++;
	} 
	victory(p1Wins, p2Wins);
	scores(p1Score, p2Score, battlefield);

	
	//NonStandardDeck player1("test.txt", true);
	//player1.printDeck();
	//player1.readCardsWar("test.txt");
	
	
	return 0;
	
}