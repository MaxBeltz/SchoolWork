// I promise that the work submitted here is solely my own.
//
// mbeltz
#include "CommandAdd.h"
CommandAdd::CommandAdd(){}

// Dr. Ryan: We should really use a global constant in place of the (1).
//fixed
int CommandAdd::getPriority() {return prior;}

int CommandAdd::execute(int x, int y) {return (x+y);} 