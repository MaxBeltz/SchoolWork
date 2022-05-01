// I promise that the work submitted here is solely my own.
//
// mbeltz

#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>

class Visitor;

class Node{
	public:
	
	Node(): left(), right() {};
	
	//destructor
	virtual ~Node() {};
	
	virtual int getPriority() = 0;
	
	virtual int visit(Visitor & v) = 0;
	
	Node* left;
	Node* right;
	
};

#endif 