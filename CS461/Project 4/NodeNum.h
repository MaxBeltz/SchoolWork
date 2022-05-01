// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _NODENUM_H_
#define _NODENUM_H_

#include "Node.h"
#include "Visitor.h"

class NodeNum: public Node{
	public:
	
	NodeNum();
	
	NodeNum(int val);
	
	~NodeNum() {}; 
	
	int getPriority();
	
	int visit(Visitor & v);
	
	int getValue();
	
	
	private:
		int value;
		const int prior = 0;
		bool valid;
	
};
#endif 