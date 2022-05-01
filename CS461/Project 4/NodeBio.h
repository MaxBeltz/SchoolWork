// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _NODEBIO_H_
#define _NODEBIO_H_

#include "Node.h"
#include <stdexcept> 


class NodeBio: public Node{
	public:
	
	NodeBio(void);
	
	virtual ~NodeBio();
	
	virtual int getPriority(); 
	
	virtual int visit(Visitor & v) {return 0;}
	
	
	private:
		const int prior = 0;

};

#endif 