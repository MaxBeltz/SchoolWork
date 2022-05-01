// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _NODEADD_H_
#define _NODEADD_H_

#include "Visitor.h"
#include "NodeBio.h"

class NodeAdd: public NodeBio{
	public:
	
	NodeAdd();
	
	~NodeAdd(); 
	
	int getPriority();
	
	int visit(Visitor & v);
	
	private:
		const int prior = 1;
	
};
#endif 