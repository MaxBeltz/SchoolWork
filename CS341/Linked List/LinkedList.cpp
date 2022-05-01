#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

LinkedList::~LinkedList()
{
	
}

void LinkedList::printList()
{
	Node * printNode = head;
	while(printNode != nullptr)
	{
		std::cout << printNode->item << std::endl;
		printNode = printNode->next;
	}
	
}

void LinkedList::insertNode(std::string itemToAdd) //inserting at the end
{
	Node * newNode = newNode();
	newNode->item = itemToAdd;
	
	if(isEmpty()){
		head = newNode;
		tail = newNode;
	}
	else{
		tail->next = newNode;
		tail = newNode;
	}
}

bool LinkedList::isEmpty()
{
	return (head == nullptr);
}

int LinkedList::length()
{
	int count = 0;
	Node * tempNode = head;
	while(tempNode != nullptr){
		count++
		tempNode = tempNode->next;
	}
	return count;	
}

Node * LinkedList::search(std::string itemToFind)
{
	if(isEmpty())
		return nullptr;
	else
	{
		Node * currentNode = head;
		while(currentNode != nullptr){
			if(currentNode->item == itemToFind)
				return currentNode;
			else{
				currentNode = currentNode->next;
			}	
		}
	}
	return nullptr;
}

void LinkedList::insertNode(Node * iPtr, std::string itrmToAdd){
	Node * newNode = new Node();
	newNode->item = itemToAdd;
	if (iPtr->next == nullptr)
		tail = newNode;
	newNode->next = iPtr->next;
	iPtr->next = newNode;
	return;
}

/*void LinkedList::deleteNode(Node * dPtr){
	
	if(isEmpty())
		return;
	else if(head == tail){
		delete head;
		head = tail = nullptr;
	}
	else{
		if(dPtr == head){
			head = head->next;
			delete dPtr;
		}
		else if(dPtr == tail){
			
		}
		else{
			
		
	}
	return;
}*/

void LinkedList::deleteNode(Node * dPtr){
	if(isEmpty)
		return;
	if(dptr == tail)
		return;
	Node * tempPtr = dPtr->next;
	dptr->next = tempPtr->next;
	if(tempPtr == tail)
		tail = dptr;
	delete tempPtr;
}