// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _COMMANDADD_H_
#define _COMMANDADD_H_

#include "CommandBio.h"
class CommandAdd: public CommandBio{
	public:
	
	CommandAdd();
	
	~CommandAdd() {}; 
	
	int getPriority();
	
	int execute(int x, int y);
	
	private:
		const int prior = 1;
	
};
#endif 