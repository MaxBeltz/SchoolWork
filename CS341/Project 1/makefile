otpt: card.o standardDeck.o War.cpp NonStandardDeck.o deckofcards.o
	g++ card.o standardDeck.o NonStandardDeck.o deckofcards.o War.cpp -o otpt

NonStandardDeck.o: deckofcards.o NonStandardDeck.cpp
	g++ -c NonStandardDeck.cpp
	
standardDeck.o: deckofcards.o standardDeck.cpp
	g++ -c standardDeck.cpp
	
deckofcards.o: card.o deckofcards.cpp
	g++ -c deckofcards.cpp
	
card.o: card.cpp
	g++ -c card.cpp

clean:
	rm -f *.o otpt