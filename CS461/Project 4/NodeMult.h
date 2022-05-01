// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _COMMANDMULT_H_
#define _COMMANDMULT_H_

#include "NodeBio.h"
#include "Visitor.h"

class NodeMult: public NodeBio{
	public: 
	NodeMult();
	
	~NodeMult() {};
	
	int getPriority();
	
	int visit(Visitor & v);
	
	private:
		const int prior = 5;
};
#endif 