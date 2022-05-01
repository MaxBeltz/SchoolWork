// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _NODEMOD_H_
#define _NODEMOD_H_

#include "NodeBio.h"
#include "Visitor.h"


class NodeMod: public NodeBio{
	public:
	
	NodeMod();
	
	~NodeMod() {}; 
	
	int getPriority();
	
	int visit(Visitor & v);
	
	private:
		const int prior = 3;
	
};
#endif 