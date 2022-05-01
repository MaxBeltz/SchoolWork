// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _COMMANDDEV_H_
#define _COMMANDDEV_H_

#include "CommandBio.h"
class CommandDev: public CommandBio{
	public:
	CommandDev();
	
	~CommandDev() {};
	
	int getPriority();
	
	int execute(int x, int y);
	
	private:
		const int prior = 4;
	
};
#endif 