// I promise that the work submitted here is solely my own.
//
// mbeltz
#include "CommandSub.h"
CommandSub::CommandSub() {}

// Dr. Ryan: We should really use a global constant in place of the (2).
//fixed
int CommandSub::getPriority() {return prior;}

int CommandSub::execute(int x, int y) {return (x-y);} 