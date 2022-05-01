#include <iostream>

#include "HashTable.h"
#include "linearProbing.h"
#include "chaining.h"
#include "Cuckoo.h"



void secondSelection(int hashNum);
void firstSelection (int input);
void menu();

void menu(){
	int input = 0;
	cout << "Welcome to the Anglo-Saxon Castle" << endl;
	cout << "Where it is BYOP (Bring Your Own Plate)" << endl;
	cout << endl << "1) Linear Probing" << endl << "2) Separate Chaining" 
	<< endl << "3) Cuckoo Hashing" << endl << "0) Quit" << endl;
	cout << "Please enter your choice: ";
	
	cin >> input;
	
	firstSelection(input);
}

void firstSelection (int input){
	if(input == 0){
		cout << "Ok, leave or whatever" << endl;
		cout << "Its not like I care or anything" << endl;
		cout << ":(" << endl;
		return;
	}
	else if (input == 1)
		cout << "We doin the Str8 boiiiii" << endl;
	else if (input == 2)
		cout << "Like my parents, you have chosen to seporate" << endl;
	else if (input == 3)
		cout << "You did a cyaazyt" << endl;
	else{
		cout << "You did a dumb dumb, try again" << endl;
		menu();
		return;
	}
	secondSelection(input);
}

void secondSelection(int hashNum){
	HashTable *hash;
	int input = -1;
	int hashInt = 0;
	string filename = "";
	if (hashNum == 1)
		hash = new linearProbing();
	else if(hashNum == 2)
		hash = new chaining();
	else
		hash = new Cuckoo();
	while (input != 0){
		cout << "1) Load Table From File" << endl << "2) Insert" << endl << "3) Search" << endl
		<< "4) Delete" << endl << "5) Print Hash Table" << endl << "0) Quit" << endl << endl;
		
		cout << "Please enter your choice: ";
		cin >> input;
		
		if (input == 1){
			cout << "Please enter the file name: ";
			cin >> filename;
			cout << "Loading..." << endl << endl;
			if(hash->load(filename))
				cout << "Loaded Sucessfully" << endl;
			else
				cout << "Failed" << endl;
		}
		else if (input == 2){
			cout << "please enter the number you want to insert: ";
			cin >> hashInt;
			cout << "Attempting to insert " << hashInt << endl << endl;
			if(hash->insert(hashInt))
				cout << "Inserted Sucessfully" << endl;
			else
				cout << "Failed" << endl;
		}
		else if (input == 3){
			cout << "please enter the number you want to search: ";
			cin >> hashInt;
			cout << "Attempting to search " << hashInt << endl << endl;
			if(hash->search(hashInt))
				cout << hashInt << " is in the table" << endl;
			else
				cout << hashInt << " is not in the table" << endl;
		}
		else if (input == 4){
			cout << "Please enter the number you want to delete: ";
			cin >> hashInt;
			cout << "Attempting to Delete " << hashInt << endl << endl;
			if(hash->remove(hashInt))
				cout << hashInt << " deleted" << endl;
			else
				cout << hashInt << " faild to delete" << endl;
		}
		else if(input == 5)
			hash->print();
		else if(input == 0){
			cout << "I bid you adu and a fair thee well my good person" << endl;
			delete hash;
			return;
		}
		else
			cout << "Enter a valid number you dumb dumb, there are like 6 of them" << endl;	
	}
}

int main(){
	menu();
	//HashTable *hash;
	//hash = new chaining();
	//delete hash;


	return 0;
}