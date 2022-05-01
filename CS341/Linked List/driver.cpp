#include "LinkedList.h"
#include <iostream>

int main()
{
	LinkedList * groceryList = new LinkedList();
	
	groceryList->insertNode("Milk");
	groceryList->insertNode("Bread");
	groceryList->insertNode("Eggs");
	groceryList->insertNode("Cereal");
	
	groceryList->printList();
	
	Node * foundNode = groceryList->search("Bread");
	std::cout << foundNode->item << std::endl;
	
	bool empty = groceryList->isEmpty
	if(empty == true)
		std::cout <<"List is empty" << endl;
	else
		std::cout << "List is " << groceryList->length() << " items long" << endl;

}