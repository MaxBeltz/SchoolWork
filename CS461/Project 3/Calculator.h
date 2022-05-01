// I promise that the work submitted here is solely my own.
//
// mbeltz


//To DO: fix valgrind from calculate


#include "calculatorFactory.h"
#include <stack>
#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream> 

class Calculator{
	public:
	//Base constructor 
	Calculator();
	
	//destructor
	~Calculator();
	
	//calculate function that has the equation input within it
	void calculate();
	
	//calculate function that is sent the equation
	void calculate(std::string equation);
	
	//clears the exporession stack
	void clear();

	private:
	
		//claculates the final answer
		void finalAns(int numOpenPar);
		void stackInteract(Command * toPush);
		Command * builder(std::string function);
		bool Parentheses(std::string par, int & num, bool nextNum);
		
		std::stack <Command *> numbers;
		std::stack <Command *> expression;
		calculatorFactory factory;
};
