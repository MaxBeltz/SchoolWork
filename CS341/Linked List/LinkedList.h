#include "Node.h"

class LinkedList{
	Node * head;
	Node * tail;
	
	LinkedList();
	~LinkedList();
	
	bool isEmpty();
	int length();	
	void printList();
	
	void insertNode(std::string itemToAdd);
	void insertNode(Node *, std::string itrmToAdd);
	void deleteNode(Node *);
	
	Node * search(std::string itemToFind);
}