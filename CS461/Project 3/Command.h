// I promise that the work submitted here is solely my own.
//
// mbeltz

#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <stack>
#include <iostream>

class Command{
	public:
	
	//fixing no need for .cpp
	
	//default construction
	Command() {};
	
	//destructor
	virtual ~Command() {};
	
	// Dr. Ryan: Why not make these pure virtual then?
	//fixed
	virtual int getPriority() = 0;
	
	//virtual vunction, will be used by children to execute purpose
	virtual int run(std::stack <Command *> &funct) = 0;
	
	
};

#endif 