// I promise that the work submitted here is solely my own.
//
// mbeltz
#include "CommandMult.h"
CommandMult::CommandMult() {}

// Dr. Ryan: We should really use a global constant in place of the (5).
//fixed
int CommandMult::getPriority() {return prior;}

int CommandMult::execute(int x, int y) {return (x*y);} 