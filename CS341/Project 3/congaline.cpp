#include "congaline.h"

CongaLine::CongaLine() {
	head = NULL;
	tail = NULL;
	doubleEdgedSword = NULL;
	barHeight = 10;
	pirateFile.open("portal.txt");
	commandFile.open("commands.txt");
	fill();
}

CongaLine::~CongaLine() {
	doubleEdgedSword = NULL;
	while(head != NULL)
		deleteAtNode(head);
	pirateFile.close();
	commandFile.close();
}

int CongaLine::length(){
	int count = 0; 
	Node * tempNode = head;
	
	while(tempNode != NULL){
		count++;
		tempNode = tempNode->next;
	}
	
	return count;
}

void CongaLine::fill(){
	string pirateName = "";
	int pirateHeight = 0;
	while(length() < 20){
		Pirate newPirate;
		pirateFile >> pirateName >> pirateHeight;
		newPirate.name = pirateName;
		newPirate.height = pirateHeight;
		insertAtTail(newPirate);
	}
}

void CongaLine::setBar(int height) {
	if(height < 0)
		height = 0;
	if(height > 15)
		height = 15;
	barHeight = height;
}

void CongaLine::lowerBar() {
	barHeight--;
	if(barHeight <0) {
		barHeight = 10;
	}
}   
 
bool CongaLine::insertAtHead(Pirate pirateToAdd){
	Node * newNode = new Node();
	newNode->pirate = pirateToAdd;
	
	if(head == nullptr) //list is empty
	{
		head = newNode;
		tail = newNode;
		doubleEdgedSword = head;
	}
	else
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	return true;
}	

bool CongaLine::insertAtTail(Pirate pirateToAdd){
	Node * newNode = new Node();
	newNode->pirate = pirateToAdd;
	
	if(head == nullptr) //list is empty
	{
		head = newNode;
		tail = newNode;
		doubleEdgedSword = head;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	return true;
}
	
	
Node * CongaLine::search(int position){
	if(head == NULL || position > length() || position < 0){
		return NULL;
	}
	Node * currentNode = head;
	for(int count = 0; count < position; count++){
		currentNode = currentNode->next;
	}
	return currentNode;
}	

bool CongaLine::deleteAtNode(Node * toBeKilled){
	if (length() == 0)
		return false;
	if (head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	else if (toBeKilled == head){
		if(doubleEdgedSword == toBeKilled)
			doubleEdgedSword = doubleEdgedSword->next;
		head = head->next;
		head->prev = NULL;
	}
	else if(toBeKilled == tail){
		if(doubleEdgedSword == toBeKilled)
			doubleEdgedSword = doubleEdgedSword->prev;
		tail = tail->prev;
		tail->next = NULL;
	}
	else{
		if(doubleEdgedSword == toBeKilled)
			doubleEdgedSword = doubleEdgedSword->next;
		toBeKilled->prev->next = toBeKilled->next;
		toBeKilled->next->prev = toBeKilled->prev;
	}	
	//toBeKilled->pirate.print();
	//cout << endl;
	delete toBeKilled;
	return true;
}

void CongaLine::hammer(int posOfKill){
	if(posOfKill < 0 || posOfKill > 19)
		return;
	Node * markedForDeath = search(posOfKill);
	deleteAtNode(markedForDeath);
	//Pirate freshmeat;
	//insertAtTail(freshmeat);
	fill();
}	

int CongaLine::getIntPos(Node * looking){
	if(head == NULL){
		return -1;
	}
	Node * currentNode = head;
	//cout << "Head:";
	//head->pirate.print();
	//cout << "Looking:";
	//looking->pirate.print();
	for(int count = 0; count < length(); count++){
		//cout << "Current Node:";
		//currentNode->pirate.print();
		 if(currentNode == looking)
			 return count;
		 currentNode = currentNode->next;
	}
	return -1;
}

        
void CongaLine::lshift(int numofleftMoves){
	for(int moves = numofleftMoves; moves > 0; moves--){
		if(doubleEdgedSword == head)
			return;
		if (!(doubleEdgedSword->prev->pirate.canLimbo(barHeight))){
			cout << "Dead:" << endl;
			doubleEdgedSword->prev->pirate.print();
			hammer(getIntPos(doubleEdgedSword->prev));
		}
		else{
			cout << "Lived:" << endl;
			doubleEdgedSword->prev->pirate.print();
			doubleEdgedSword->prev->pirate.numLimbos++;
			//doubleEdgedSword->next = doubleEdgedSword;
			doubleEdgedSword = doubleEdgedSword->prev;
		}
	}
}
	
void CongaLine::rshift(int numofrightMoves){
	for(int moves = numofrightMoves; moves > 0; moves--){
		if(doubleEdgedSword == tail)
			return;
		if (!(doubleEdgedSword->next->pirate.canLimbo(barHeight))){
			cout << "Dead:" << endl;
			doubleEdgedSword->next->pirate.print();
			hammer(getIntPos(doubleEdgedSword->next));
		}
		else{
			cout << "Lived:" << endl;
			doubleEdgedSword->next->pirate.print();
			doubleEdgedSword->next->pirate.numLimbos++;
			//doubleEdgedSword->prev = doubleEdgedSword;
			doubleEdgedSword = doubleEdgedSword->next;
		}
	}
}	

void CongaLine::tacticalNuke(){
	for(int i=0; i<20; i++)
		hammer(0);
}	

void CongaLine::run(){
	Pirate checkkilled;
	string commandNum = "";
	string command = "";
	//cout << "Here" << endl;
	while(!commandFile.eof()){
		commandFile >> command >> commandNum;
		cout << endl << endl << command << " " << commandNum << endl << endl;
		if(command == "lshift")
			lshift(stoi(commandNum));
		else if(command == "rshift")
			rshift(stoi(commandNum));
		else if(command == "lowerbar"){
			lowerBar();
			cout << "Bar Height: " << barHeight;
		}
		else if(command == "setbar"){
			setBar(stoi(commandNum));
			cout << "Bar Height: " << barHeight;
		}
		else if(command == "hammer")
			hammer(stoi(commandNum));
		else if(command == "tacticalnuke")
			tacticalNuke();
		else
			cout << "invalid command" << endl;
		cout << endl << endl;
		print();
		
	}
}

void CongaLine::print(){
	for(int i=0; i<length(); i++)
		search(i)->pirate.print();
}