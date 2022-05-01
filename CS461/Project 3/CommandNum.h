// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _COMMANDNUM_H_
#define _COMMANDNUM_H_

#include "Command.h"
class CommandNum: public Command{
	public:
	
	CommandNum(int val);
	
	~CommandNum() {}; 
	
	int getPriority();
	
	int run(std::stack <Command *> &funct);
	
	int getValue();
	
	
	private:
		int value;
		const int prior = 0;
	
};
#endif 