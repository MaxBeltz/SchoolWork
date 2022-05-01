// I promise that the work submitted here is solely my own.
//
// mbeltz

#ifndef _CALCULATORFACTORY_H_
#define _CALCULATORFACTORY_H_

// Dr. Ryan: These includes need to go inside our Header Guard
//			 so we can prevent them from being included multiple
//			 times during the compilation process.
//fixed and moved
#include "CommandAdd.h"
#include "CommandSub.h"
#include "CommandMod.h"
#include "CommandDev.h"
#include "CommandMult.h"
#include "CommandNum.h"
#include "CommandPar.h"

class calculatorFactory{
	public:
	//constructor
	calculatorFactory();
	
	//destructor
	~calculatorFactory();
	
	//builds an add command
	CommandAdd* buildAdd();
	
	//builds a subtrasction command
	CommandSub* buildSub();
	
	//builds a modulus command
	CommandMod* buildMod();
	
	//builds a devide command
	CommandDev* buildDev();
	
	//builds a multiply command
	CommandMult* buildMult();
	
	//builds a number command
	CommandNum* buildNum(int val);
	
	//builds a (
	CommandPar* buildPar();
	
	
};

#endif 