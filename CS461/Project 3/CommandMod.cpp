// I promise that the work submitted here is solely my own.
//
// mbeltz
#include "CommandMod.h"
CommandMod::CommandMod(){}

// Dr. Ryan: We should really use a global constant in place of the (3).
//fixed
int CommandMod::getPriority() {return 3;}

// Dr. Ryan: Don't we need to make sure that we aren't attempting to
//			 MOD by 0 as that will trigger the same result as dividing
//			 by 0.
//added exception
int CommandMod::execute(int x, int y) {
	if(y == 0)
		throw std::runtime_error("Math error: Attempted to mod by Zero\n");
	return (x%y);
	} 