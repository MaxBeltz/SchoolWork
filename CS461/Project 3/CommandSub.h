// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _COMMANDSUB_H_
#define _COMMANDSUB_H_

#include "CommandBio.h"
class CommandSub: public CommandBio{
	public:
	CommandSub();
	
	~CommandSub() {}; 
	
	int getPriority();
	
	int execute(int x, int y);
	
	private:
		const int prior = 2;
	
};
#endif 