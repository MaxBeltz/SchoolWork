// I promise that the work submitted here is solely my own.
//
// mbeltz
#include "calculatorFactory.h"


calculatorFactory::calculatorFactory() {}

calculatorFactory::~calculatorFactory() {}

CommandAdd * calculatorFactory::buildAdd() {return new CommandAdd();}

CommandSub * calculatorFactory::buildSub() {return new CommandSub();}

CommandMod * calculatorFactory::buildMod() {return new CommandMod();}

CommandDev * calculatorFactory::buildDev() {return new CommandDev();}

CommandMult * calculatorFactory::buildMult() {return new CommandMult();}

CommandNum * calculatorFactory::buildNum(int val) {return new CommandNum(val);}

CommandPar * calculatorFactory::buildPar() {return new CommandPar();}
	