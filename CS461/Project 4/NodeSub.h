// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _NODESUB_H_
#define _NODESUB_H_

#include "NodeBio.h"
#include "Visitor.h"

class NodeSub: public NodeBio{
	public:
	NodeSub();
	
	~NodeSub() {}; 
	
	int getPriority();
	
	int visit(Visitor & v);
	
	private:
		const int prior = 2;
	
};
#endif 