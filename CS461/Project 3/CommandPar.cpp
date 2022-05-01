// I promise that the work submitted here is solely my own.
//
// mbeltz

#include "CommandPar.h"

CommandPar::CommandPar() {}
	
CommandPar::~CommandPar() {} 
	
int CommandPar::getPriority() {return prior;}

int CommandPar::run(std::stack <Command *> &funct) {return 0;}