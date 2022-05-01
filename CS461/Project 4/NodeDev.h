// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _NODEDEV_H_
#define _NODEDEV_H_

#include "NodeBio.h"
#include "Visitor.h"

class NodeDev: public NodeBio{
	public:
	NodeDev();
	
	~NodeDev() {};
	
	int getPriority();
	
	int visit(Visitor & v);
	
	private:
		const int prior = 4;
	
};
#endif 