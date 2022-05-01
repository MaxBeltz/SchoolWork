// I promise that the work submitted here is solely my own.
//
// mbeltz

#ifndef _COMMANDBIO_H_
#define _COMMANDBIO_H_

#include "Command.h"
#include <stdexcept> 

class CommandBio: public Command{
	public:
	
	//default construction
	CommandBio(void);
	
	//destructor
	virtual ~CommandBio();
	
	virtual int getPriority(); 
	
	//the function that calculates from the stack
	int run(std::stack <Command *> &funct);
	
	// Dr. Ryan: Shouldn't this be Pure Virtual?
	//fixed
	//virtual vunction, will be used by children to execute purpose
	virtual int execute(int x, int y) = 0;
	
	private:
		const int prior = 0;

};

#endif 