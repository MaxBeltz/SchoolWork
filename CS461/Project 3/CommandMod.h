// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _COMMANDMOD_H_
#define _COMMANDMOD_H_

#include "CommandBio.h"
class CommandMod: public CommandBio{
	public:
	
	CommandMod();
	
	~CommandMod() {}; 
	
	int getPriority();
	
	int execute(int x, int y);
	
	private:
		const int prior = 3;
	
};
#endif 