// I promise that the work submitted here is solely my own.
//
// mbeltz
#include "CommandBio.h"
CommandBio::CommandBio (void) {}

CommandBio::~CommandBio() {}

int CommandBio::getPriority() {return prior;}


int CommandBio::run (std::stack <Command *> &funct){
	int y = (funct.top()->run(funct));
	delete funct.top();
	funct.pop();
	int x = (funct.top()->run(funct));
	delete funct.top();
	funct.pop();
	int val = execute(x, y);
	return val;
}