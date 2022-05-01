#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;


//Made by Max Beltz and Ian Wallok
//commented out code is for testing
class Node {
	public: 
		Node * parent;
		int value[6];
		Node * child[6];
	
	
	public:
	//Node(int val); // constructor
	//Node(Node * child);
	//int numChildren();
	//void absorb(Node * newChild);
	//void discard(Node * removeChild);
	
	
	Node (int val)
	{
		parent = NULL;
		for (int i=0; i<6; i++){
			value[i] = NULL;
			child[i] = NULL;
		}
		value[5] = val;
	}
	
	Node(Node * childNode) //making a non leaf, NOTE THIS IS GARBO
	{
		this->parent = NULL;
		for (int i=0; i<6; i++){
			this->value[i] = NULL;
			this->child[i] = NULL;
		}
		this->child[5] = childNode;
		this->value[5] = childNode->value[5];
		childNode->parent = this;
	}
	
	int numChildren()
	{
		int count = 0;
		for (int i=0; i<6; i++){
			if (this->child[i] != NULL)
				count++;
		}
		return count;
	}
	
	void absorb(Node * newChild) 
	{
		//cout << "Number of children " << this->numChildren() << endl;
		if (this->numChildren() == 2) //only 2 children, easy case
		{
			//cout << "Num Child" << endl;
			if(this->value[1] > newChild->value[5]){//the new child is the lowest
				//cout << "Right Path" << endl;
				this->child[3] = this->child[1];
				this->value[3] = this->value[1];
				this->child[1] = newChild;
				this->value[1] = newChild->value[5];
			}
			else if (this->value[1] > newChild->value[5]){ //the new child is the mid
				//cout << "Wrong Path" << endl;
				this->child[3] = newChild;
				this->value[3] = newChild->value[5];
			}
			else { //The new child is the new max of the tree
				this->child[3] = this->child[5];
				this->value[3] = this->value[5];
				this->child[5] = newChild;
				this->value[5] = newChild->value[5];
				this->TrickleUp(this->value[5]);
			}
			newChild->parent = this;
		}
		else if (newChild->value[5] > this->value[5]){ //The new child is the max of the tree and we have 3 values
			int next = this->value[5];
			Node * nextNode = new Node(next);
			this->child[5] = newChild;
			this->value[5] = newChild->value[5];
			if(this->parent != NULL){
				this->parent->TrickleUp(this->value[5]);
				newChild->parent = this;
			}
			this->absorb(nextNode);
		}
		else if (this->parent != NULL){ //three children and not the root
			//cout << "Not Null Parent " << endl;
			Node * newNode = new Node(0);
			//cout <<"Alive 1" << endl;
			Node * par = this->parent;
			cout << "Parent val: " <<this->parent->value[5] << endl;
			//cout <<"Alive 2" << endl;
			newNode->parent = par;
			//cout <<"Alive 3" << endl;
			newNode->child[1] = this->child[1];
			//cout <<"Alive 4" << endl;
			newNode->value[1] = this->value[1];
			//cout <<"Alive 5" << endl;
			if(newChild->value[5] < this->value[3]){ //we put the new child in the new node
				//cout << "Should be Here " << endl;
				if(newChild->value[5] > this->value[1]){
					newNode->child[5] = newChild; 
					newNode->value[5] = newChild->value[5];
					newNode->child[1]->parent = newNode;
				}
				else{
					newNode->child[5] = newNode->child[1];
					newNode->value[5] = newNode->value[1];
					newNode->child[1] = newChild; 
					newNode->value[1] = newChild->value[5];
					newNode->child[3]->parent = newNode;
				}
				newChild->parent = newNode;
				this->child[1] = this->child[3];
				this->value[1] = this->value[3];
				this->child[3] = NULL;
				this->value[3] = NULL;
			}
			else //the child is larger than the mid
			{
				//cout << "Not Here" << endl;
				newNode->child[5] = this->child[3]; 
				newNode->value[5] = this->value[3];
				this->child[1] = newChild;
				this->value[1] = newChild->value[5];
				newChild->parent = this;
				this->child[3] = NULL;
				this->value[3] = NULL;
				newNode->child[1]->parent = newNode;
				newNode->child[5]->parent = newNode;
			}
				par->absorb(newNode);
		}
		else{
			Node * par = new Node(0); //We are on the root level and need to make a new root
			//cout << "Null Parent " << endl;
			Node * newNode = new Node(0);
			//cout <<"Alive 1" << endl;
			//cout << this->parent->value[5] << endl;
			//cout <<"Alive 2" << endl;
			newNode->parent = par;
			//cout <<"Alive 3" << endl;
			newNode->child[1] = this->child[1];
			//cout <<"Alive 4" << endl;
			newNode->value[1] = this->value[1];
			//cout <<"Alive 5" << endl;
			if(newChild->value[5] < this->value[3]){
				//cout << "Should be Here " << endl;
				if(newChild->value[5] > this->value[1]){
					newNode->child[5] = newChild; 
					newNode->value[5] = newChild->value[5];
				}
				else{
					newNode->child[5] = newNode->child[1];
					newNode->value[5] = newNode->value[1];
					newNode->child[1] = newChild; 
					newNode->value[1] = newChild->value[5];
				}
				this->child[1] = this->child[3];
				this->value[1] = this->value[3];
				this->child[3] = NULL;
				this->value[3] = NULL;
				newChild->parent = newNode;
			}
			else //the child is larger than the mid
			{
				//cout << "Not Here" << endl;
				newNode->child[5] = this->child[3]; 
				newNode->value[5] = this->value[3];
				this->child[1] = newChild;
				this->value[1] = newChild->value[5];
				this->child[3] = NULL;
				this->value[3] = NULL;
				newChild->parent = this;
			}
				//cout <<"Alive 6" << endl;
				par->child[1] = newNode;
				//cout <<"Alive 7" << endl;
				par->value[1] = newNode->value[5];
				//cout <<"Alive 8" << endl;
				par->child[5] = this;
				//cout <<"Alive 9" << endl;
				par->value[5] = this->value[5];
				//cout <<"Alive 10" << endl;
				newNode->parent = par;
				this->parent = par;
				
		
		}
	}
	void discard(Node * removeChild) //removing a node
	{
		//cout << "Start Discard" << endl;
		Node * par = this->parent;
		//cout << "Post Par" << endl;
		int position = 0; //position of this node from its parent 
		int mypos = 0; //postition of the removed item
		if(this->value[5] == par->value[1])
			mypos = 1;
		else if(this->value[5] == par->value[3])
			mypos = 3;
		else
			mypos = 5;
		//cout << endl << endl << "My Children:" << this->numChildren() << endl << endl;
		if(this->value[1] == removeChild->value[5])
		{
			this->child[1] = this->child[3];
			this->value[1] = this->value[3];
			position = 1;
		}
		else if (this->value[5] == removeChild->value[5])
		{
			this->child[5] = this->child[3];
			this->value[5] = this->value[3];
			position = 5;
		}
		this->child[3] = NULL;
		this->value[3] = NULL;
		//cout << this->numChildren() << " " << position << " " << this->value[5] << " " << removeChild->value[5]  << " " << par->value[1] << endl << endl;
		if(this->numChildren() == 2){ //easy case
			//cout <<"Alive 1" << endl;
			if(par != NULL)
			{
				//cout <<"Alive 2" << endl;
				if (position == 5){ //redevine the max value
					this->TrickleUp(this->value[5]);
				}
			}
		}
		else //difficult cases
		{
			//cout <<"Alive 3" << endl;
			int totChildren = 0;
			for(int i=1; i<7; i+=2) //count the total number of siblings
			{
				if (par->child[i] != NULL)
					totChildren += par->child[i]->numChildren();
			}
			//cout << endl << endl << totChildren << " place " << position << endl << endl;
			if(totChildren >= 5)
			{
				if (mypos == 1)//removing from the first node will result in the same code
				{
					if (position == 1) //we removed the first value so we push to five for ease of use
					{
						this->child[1] = this->child[5];
						this->value[1] = this->value[5];
					}
						this->child[5] = par->child[3]->child[1];
						this->value[5] = par->child[3]->value[1];
						par->value[1] = this->value[5];
						//cout << endl << endl << par->child[3]->child[1]->value[5] << endl << endl;
						par->child[3]->discard(par->child[3]->child[1]);
						par->TrickleUp(this->value[5]);
				}
				else if (totChildren == 6 && mypos == 3) //we need to figure out which side has 2 children to push to
				{
					if(par->child[1]->numChildren() == 3)
					{
						if(position == 5)
						{
							this->child[5] = this->child[1];
							this->value[5] = this->value[1];
							par->value[mypos] = this->value[5];
						}
						this->child[1] = par->child[mypos-2]->child[5];
						this->value[1] = par->child[mypos-2]->value[5];
						//cout << "Dumb " << this->value[1] << endl; 
						par->child[mypos-2]->discard(par->child[mypos-2]->child[5]);
							
					}
					else{
						if (position == 1)
						{
							this->child[1] = this->child[5];
							this->value[1] = this->value[5];
						}
							this->child[5] = par->child[5]->child[1];
							this->value[5] = par->child[5]->value[1];
							par->value[3] = this->value[5];
							//cout << endl << endl << par->child[3]->child[1]->value[5] << endl << endl;
							par->child[5]->discard(par->child[5]->child[1]);	
					}
				}
				else if (totChildren == 5 && mypos == 3) //push right
				{
					if (position == 5)
					{
						this->child[5] = this->child[1];
						this->value[5] = this->value[1];
					}
					par->child[5]->child[3] = par->child[5]->child[1];
					par->child[5]->value[3] = par->child[5]->value[1];
					//cout << par->child[5]->value[3] << endl;
					par->child[5]->child[1] = this->child[5];
					par->child[5]->value[1] = this->value[5];
					//cout << par->child[5]->value[1] << endl;
					//par->discard(par->child[3]);
					par->child[3] = NULL;
					par->value[3] = NULL;
					//cout << "Here" << endl;
				}
				else //removed from the 5th position
				{
					if(position == 5)
					{
						this->child[5] = this->child[1];
						this->value[5] = this->value[1];
						par->value[mypos] = this->value[5];
					}
					this->child[1] = par->child[mypos-2]->child[5];
					this->value[1] = par->child[mypos-2]->value[5];
					//cout << "Dumb " << this->value[1] << endl; 
					par->child[mypos-2]->discard(par->child[mypos-2]->child[5]);
					par->TrickleUp(this->value[5]);
					
				}
			}
			else if(totChildren==4) //need to move 1 value to your node from the other node
			{
				//cout <<"Alive 4" << endl;
				if(mypos == 1)
				{
					if (position == 1)
					{
						this->child[1] = this->child[5];
						this->value[1] = this->value[5];
					}
					this->child[5] = par->child[5]->child[1];
					this->value[5] = par->child[5]->value[1];
					//cout << this->value[1] << " " << this->value[5];
					par->value[1] = this->value[5];
					par->child[5]->discard(par->child[5]->child[1]);
					par->TrickleUp(this->value[5]);
				}
				else
				{
					if (position == 5)
					{
						this->child[5] = this->child[1];
						this->value[5] = this->value[1];
					}
					this->child[1] = par->child[1]->child[5];
					this->value[1] = par->child[1]->value[5];
					par->child[1]->discard(par->child[1]->child[5]);
				}
			}
			else if (totChildren == 3) //this level is dead, we need to rebuild and push up
			{
				//cout <<"Alive 5" << endl;
				if(mypos == 1)
				{
					//cout <<"Alive 6" << endl;
					if (position == 5)
					{
						this->child[5] = this->child[1];
						this->value[5] = this->value[1];
					}
					par->child[5]->child[3] = par->child[5]->child[1]; 
					par->child[5]->value[3] = par->child[5]->value[1];
					par->child[5]->child[1] = this->child[5];
					par->child[5]->value[1] = this->value[5];
					if(par->parent != NULL)
					{
						//cout <<"Alive 7" << endl;
						int parpos = 0;
						if(par->value[5] == par->parent->value[1])
							parpos = 1;
						else if(par->value[5] == par->parent->value[3])
							parpos = 3;
						else
							parpos = 5;
						par->parent->child[parpos] = par->child[5]; 
						par->parent->value[parpos] = par->value[5]; 
					}
					else{ //Make a new Root
						//cout <<"Alive 8" << endl;
						par->child[5]->parent = NULL;
						//cout <<"Alive 14" << endl;
						par->child[1] = NULL;
						//cout <<"Alive 15" << endl;
					}
				}
				else{
					if (position == 5)
					{
						cout <<"Alive 16" << endl;
						this->child[5] = this->child[1];
						this->value[5] = this->value[1];
					}
					par->child[1]->child[3] = par->child[1]->child[5]; 
					par->child[1]->value[3] = par->child[1]->value[5];
					//cout << par->child[1]->value[3] << endl;
					par->child[1]->child[5] = this->child[5];
					par->child[1]->value[5] = this->value[5];
					//cout << par->child[1]->value[5] << endl;
					if(par != NULL)
					{
						//cout <<"Alive 17" << endl;
						par->TrickleUp(this->value[5]);
						if (par->parent != NULL)
						{
							int parpos = 0;
							if(par->value[5] == par->parent->value[1])
								parpos = 1;
							else if(par->value[5] == par->parent->value[3])
								parpos = 3;
							else
								parpos = 5;
							par->child[parpos] = par->child[1]; 
						}
					}
					else{ //Make a new Root
						par->child[1]->parent = NULL;
						par->child[5] = NULL;
					}
				}
			}
		}
		
	}
	
	void TrickleUp(int newMax) //function to change values of nodes represented in their parents
	{
		int parpos = 0;
		cout <<"Alive 18" << endl;
		this->value[5] = newMax;
		cout <<"Alive 19" << endl;
		if (this->parent != NULL)
		{
			if(this->value[5] == this->parent->value[1])
				parpos = 1;
			else if(this->value[5] == this->parent->value[3])
				parpos = 3;
			else
				parpos = 5;
			this->value[parpos] = newMax;
			cout <<"Alive 20" << endl;
			if (parpos == 5)
				this->parent->TrickleUp(newMax);
			cout <<"Alive 21" << endl;
		}
	}
	
};

class Tree {
	Node * root;
	//void print(Node * start);
	
	public:
		//Tree(); // constructor
		//Node * search(int valToFind);
		//bool insert(int valToAdd);
		//bool delete(int valToKill);
	//void print();
	
	Tree(){ //constructors
		root == NULL;
	}
	Tree(Node * roo){
		root = roo;
	}
	
	void print(Node * start){ //actual print function
		if (start == NULL)
			return;
		else{
			//cout << "My Value " << start->value[5] << " : ";
			for(int i=0; i<6; i++){
				if (start->value[i] != NULL && start->value[i] != 0)
					cout << start->value[i] << " ";
			}
			cout << endl;
			for(int j=1; j<6; j+=2){
				if(start->value[1] != 0){
					//cout << "My Start " << start->value[5] << " J: " << j << endl;
					print(start->child[j]);
				}
			}
		}
	}
	void print(){ 
		print(this->root);
	}
	
	Node * search(int valToFind){ //search function rootside
		//cout <<"Alive 29" << endl;
		Node * location = NULL;
		//cout <<"Alive 30" << endl;
		Node * bigBoi = new Node(2000); //will return if node is new Max
		//cout <<"Alive 31" << endl;
		cout << valToFind << " " << root->value[5] << endl;
		if (valToFind <= root->value[1]){
			//cout <<"Alive 32" << endl;
			location = search(root->child[1], valToFind);
		}
		else if (root->numChildren() == 3 && valToFind <= root->value[3]){
			//cout <<"Alive 33" << endl;
			location = search(root->child[3], valToFind);
		}
		else if (valToFind <= root->value[5]){
			//cout << "Root Before " << endl;
			location = search(root->child[5], valToFind);
			//cout << "Root After " << endl;
		}
		else{ 
			//cout <<"Alive 34" << endl;
			return bigBoi;
		}
		return location;
	}
	
	Node * search (Node * currentNode, int valToFind){ //search function nodeside
		//cout <<"Alive 39" << endl;
		Node * location = NULL;
		cout << valToFind << " " << currentNode->value[5] << endl;
		if (currentNode->numChildren()==1 || currentNode->numChildren()==0){
			//cout <<"Alive 35" << endl;
			return currentNode;
		}
		else if (valToFind <= currentNode->value[1]){
			//cout <<"Alive 36" << endl;
			location = search(currentNode->child[1], valToFind);
		}
		else if (currentNode->numChildren() == 3 && valToFind <= currentNode->value[3]){
				//cout <<"Alive 37" << endl;
				location = search(currentNode->child[3], valToFind);
		}
		else if (valToFind <= currentNode->value[5]){
			//cout << "Child Before " << endl;
			location = search(currentNode->child[5], valToFind);
			//cout << "Child After "<< endl;
		}
		else{ 
			return NULL;
			//cout <<"Alive 40" << endl;
		}
		//cout <<"Alive 38" << endl;
		return location;
	}
	
	bool insert(int valToAdd) //insert function
	{
		Node * test = NULL;
		test = search(valToAdd);
		if (valToAdd == test->value[5])
			return false;
		if (test->value[5] == 2000) //if we are making a new max
		{
			test = search(root->value[5]);
		}
		Node * newChild = new Node(valToAdd); 
		Node * send = test->parent;
		//cout << "Number of children " << send->numChildren() << endl;
		//cout << "Send value " << send->value[5] << endl;
		send->absorb(newChild);
		if (root->parent != NULL) //if we need a new node
		{
			//cout << "Should See" << endl;
			root = root->parent;
		}
		this->reParent();
		return true;
	}
	
	bool deleteVal(int valToKill) //deletes a value
	{
		//cout <<"Alive 22" << endl;
		Node * test = NULL;
		//cout <<"Alive 24" << endl;
		test = search(valToKill);
		//cout <<"Alive 25" << endl;
		if (valToKill != test->value[5]) //if the value is not in the tree
			return false;
		//cout <<"Alive 26" << endl;
		Node * Deleted = new Node(valToKill);
		//cout <<"Alive 27" << endl;
		cout << test->value[5] << endl;
		Node * send = test->parent;
		//cout <<"Alive 28" << endl;
		cout << send->value[1] << " " << send->value[5] << endl;
		send->discard(Deleted);
		//cout <<"Alive 13" << endl;
		if (this->root->numChildren() == 1) //if we need to make a new root
		{
			//cout <<"Alive 9" << endl;
			if (root->child[1] != NULL){
				root = root->child[1];
				//cout <<"Alive 10" << endl;
			}
			else if (root->child[3] != NULL){
				root = root->child[3];
				//cout <<"Alive 11" << endl;
			}
			else{
				root = root->child[5];
				//cout <<"Alive 12" << endl;
			}
		}
		this->reParent();
	}
	
	void reParent (){ //initial function to make sure all parents are correct
	//Note this is hella ineffiecient
		root->child[1]->parent = root;
		this->reParent(root->child[1]);
		if (root->child[3] != NULL){
			root->child[3]->parent = root;
			this->reParent(root->child[3]);
		}
		root->child[5]->parent = root;
		this->reParent(root->child[5]);
	}
	void reParent(Node * par)
	{
		if (par->numChildren() == 1 || par->numChildren() == 0)
			return;
		par->child[1]->parent = par;
		this->reParent(par->child[1]);
		if (par->child[3] != NULL){
			par->child[3]->parent = par;
			this->reParent(par->child[3]);
		}
		par->child[5]->parent = par;
		this->reParent(par->child[5]);
	}
};


int main(int argc, char * argv[]){
	Node node1 = new Node(1);
	Node node3 = new Node(3);
	Node node4 = new Node(4);
	Node node5 = new Node(5);
	Node node6 = new Node(6);
	Node node8 = new Node(8);
	Node node11 = new Node(11);
	Node node14 = new Node(14);
	Node node17 = new Node(17);
	
	Node nodeA = new Node(&node4);
	nodeA.child[1] = &node1;
	nodeA.value[1] = node1.value[5];
	nodeA.child[3] = &node3;
	nodeA.value[3] = node3.value[5];
	node1.parent = &nodeA;
	node3.parent = &nodeA;
	
	Node nodeB = new Node(&node8);
	nodeB.child[1] = &node5;
	nodeB.value[1] = node5.value[5];
	nodeB.child[3] = &node6;
	nodeB.value[3] = node6.value[5];
	node5.parent = &nodeB;
	node6.parent = &nodeB;
	
	Node nodeC = new Node(&node17);
	nodeC.child[3] = &node14;
	nodeC.value[3] = node14.value[5];
	nodeC.child[1] = &node11;
	nodeC.value[1] = node11.value[5];
	node11.parent = &nodeC;
	node14.parent = &nodeC;
	
	Node nodeH = new Node(&nodeC);
	nodeH.child[5] = &nodeC;
	nodeH.value[5] = nodeC.value[5];
	nodeH.child[3] = &nodeB;
	nodeH.value[3] = nodeB.value[5];
	nodeH.child[1] = &nodeA;
	nodeH.value[1] = nodeA.value[5];
	nodeA.parent = &nodeH;
	nodeB.parent = &nodeH;
	nodeC.parent = &nodeH;
	
	Tree * testTree = new Tree(&nodeH);
	//cout << "Parent of C " << nodeC.parent->value[5] << endl;
	testTree->print();
	//cout << "Parent check " << node3.parent->value[5] << endl;
	testTree->insert(13);
	testTree->print();
	cout << endl << endl;
	testTree->insert(2);
	testTree->print();
	cout << endl << endl;
	testTree->insert(7);
	testTree->print();
	cout << endl << endl;
	testTree->insert(9);
	testTree->print();
	cout << endl << endl;
	testTree->insert(20);
	testTree->print();
	//testTree->deleteVal(11);
	//cout << "Node H " << nodeH.numChildren() << endl;
	//cout << "Node A " << nodeA.numChildren() << endl;
	//cout << "Node1 " << node1.numChildren() << endl;
	//Node nodeTest = new Node(4);
	//nodeTest = testTree->search(15);
	//cout << "Node Test " << nodeTest.value[5] << endl;
	
	
	return 0;
}


























