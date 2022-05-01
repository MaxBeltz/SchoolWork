// I promise that the work submitted here is solely my own.
//
// mbeltz
#include "CommandNum.h"

// Dr. Ryan: Do we even want to allow access to a void Constructor in 
//			 this instance?
//fixed removed void construct
CommandNum::CommandNum(int val): value(val) {}

int CommandNum::run(std::stack <Command *> &funct) {return value; } 

// Dr. Ryan: We should really use a global constant in place of the (3).
// fixed
int CommandNum::getPriority() {return prior;}

int CommandNum::getValue() {return value;}  