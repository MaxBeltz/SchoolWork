// I promise that the work submitted here is solely my own.
//
// mbeltz
#include "NodeBio.h"
NodeBio::NodeBio (void)  {
	left = nullptr;
	right = nullptr;
}

NodeBio::~NodeBio() {}

int NodeBio::getPriority() {return prior;}
