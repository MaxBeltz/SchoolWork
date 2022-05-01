// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _COMMANDMULT_H_
#define _COMMANDMULT_H_

#include "CommandBio.h"
class CommandMult: public CommandBio{
	public: 
	CommandMult();
	
	~CommandMult() {};
	
	int getPriority();
	
	int execute(int x, int y);
	
	private:
		const int prior = 5;
};
#endif 