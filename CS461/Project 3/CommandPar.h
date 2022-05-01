// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _COMMANDPAR_H_
#define _COMMANDPAR_H_

#include "Command.h"
class CommandPar: public Command{
	public:
	//command for Parenthesis 
	//will only be used for (
	//if ), pop till (
	
	CommandPar();
	
	~CommandPar();
	
	int getPriority();
	
	int run(std::stack <Command *> &funct);
	
	
	private:
		const int prior = -1;
	
};
#endif 