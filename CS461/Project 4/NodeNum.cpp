// I promise that the work submitted here is solely my own.
//
// mbeltz
#include "NodeNum.h"

NodeNum::NodeNum(int val): value(val), valid(true) {}

NodeNum::NodeNum(): value(0), valid(false) {}

int NodeNum::visit(Visitor & v) {
	if (valid)
		return v.VisitNum(*this); 
	std::cout<< "ERROR Invalid operation" << std::endl;
	return 0;	
	} 

int NodeNum::getPriority() {return prior;}


int NodeNum::getValue() {return value;}  