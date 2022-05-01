// I promise that the work submitted here is solely my own.
//
// mbeltz
#include "CommandDev.h"
CommandDev::CommandDev() {}

// Dr. Ryan: We should really use a global constant in place of the (4).
//fixed
int CommandDev::getPriority() {return prior;}

// Dr. Ryan: We need to check and handle an attempt at dividing by 0 here
//			 otherwise you will end up with a segmentation fault.
//fixed
int CommandDev::execute(int x, int y) {
	if(y == 0)
		throw std::runtime_error("Math error: Attempted to divide by Zero\n");
	return (x/y);
	} 