#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;

#include "bitarray.h"
#include "set.h"
#include "dictionary.h"
#include <bitset>

int main() {
	cout << "We are creating a bitarray with 4 bytes" << endl;
	BitArray bits(4);
	cout << "bits length " << bits.length() << endl;
	cout << "Number of bits " << bits.bytes() << endl;
	
	cout << "We are going to fill this array with the characters: a, b, c, d" << endl;
	char letters [4] = {'a','b','c','d'};
	bits.initialize(letters);
	
	cout << "Here are the bits of the characters a, b, c, d" << endl;
	bits.nonDumbPrint();
	cout << endl;
	
	cout << "We are now setting the bit in position 1 to 1" << endl;
	bits.set(1, 1);
	bits.nonDumbPrint();
	cout << endl;
	
	
	cout << "We are now flipping the bit in position 1" << endl;
	bits.flip(1);
	bits.nonDumbPrint();
	cout << endl; 

	cout << "We are now complementing the bit, you were very handsome yesterday Mr. Bit" << endl;
	bits.complement();
	bits.nonDumbPrint();
	cout << endl;
	
	cout << "This concludes the testing of the bitArray/ part 1" << endl << endl;
	
	
	
	Set set1(4);
	Set set2(4);
	char letters1 [4] = {'a', 'b', 'c', 'd'};
	char letters2 [4] = {'+', '-', ')', '('};
	set1.initialize(letters1);
	set2.initialize(letters2);
	
	cout << "We will now be creating 2 sets containing a, b, c, and d, in the first set" << endl;
	
	cout << "Set 1" << endl;
	set1.nonDumbPrint();
	cout << endl;
	
	cout << "With the second set containing +, -, ), and (" << endl;
	cout << endl << "Set 2" << endl;
	set2.nonDumbPrint();
	cout << endl;
	
	cout << "We are now going to preform the uninon of set 1 and set 2" << endl;
	set1.setUnion(set2);
	cout << endl << "Post Union" << endl;
	set1.nonDumbPrint();
	cout << endl;

	cout << "We are going to reinitialize set 1 to its origional and intersect it with set 2" << endl;
	set1.initialize(letters1);
	set1.intersection(set2);
	cout << endl << "Post Intersection" << endl;
	set1.nonDumbPrint();
	cout << endl;
	
	cout << "We are going to reinitialize set 1 to its origional and get its difference with set 2" << endl;
	set1.initialize(letters1);
	set1.difference(set2);
	cout << endl << "Post Difference" << endl;
	set1.nonDumbPrint();
	cout << endl;
	
	cout << "This is the end of part 2, after a very brief intermission we will begin part 3" << endl;
	
	cout << "https://www.youtube.com/watch?v=dQw4w9WgXcQ&ab" << endl;
	
	cout << "We hope you enjoyed the intermission, Now back to the show" << endl << endl;
	cout << "We begin Part 3 with the same character array that we know and love, a, b, c, and of course the char the myth the legend...d" << endl;
	Dictionary dict(4);
	dict.initialize(letters1);
	cout << "We are goint to reprint the array as bits to remind you, the viewer, what to look for" << endl;
	dict.nonDumbPrint();
	cout << endl << "Beautiful, now on to the tests, we will be counting the number of 1s in a given range as well as the 4th 1 in a range" << endl << endl;
	cout << "num 1s from 7 - 27 = " << dict.rank_range(7, 27, 1) << endl;
	cout << "The 4th 1 from 7 - 27 is position: " << dict.select_range(7, 27, 4,  1) << endl;
	
	cout << "Wow, that was pretty dang slow, what the hecky. Lets see if we cen do it quicker using everyone's favorite method" << endl;
	cout << "Say it with me know: " << endl;
	cout << "You: a lookup table" << endl;
	cout << "I cant hear you " << endl;
	cout << "You: A LOOKUP TABLE" << endl;
	cout << "That's the spirit, lets see how that works..." << endl;
	cout << "num 1s from 0 - 27 using a lookup table = " << dict.rank(27, 1) << endl;
	cout << "The 4th 1 using a lookup table is in position " << dict.select(4, 0) << endl;
	
	cout << endl << "Wow, that sure was fun, thank you so much for stopping by" << endl;
	cout << "Make sure to watch out for the ghost shark on the way out and be sure to give Max and Ian an A!" << endl;
	cout << "Bye Bye now!" << endl;
}

