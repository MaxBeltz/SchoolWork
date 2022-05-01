// I promise that the work submitted here is solely my own.
//
// mbeltz
#include "Calculator.h"

Calculator::Calculator(): expression(), numbers(), factory() {}

Calculator::~Calculator() {}

void Calculator::calculate() {
	std::cout << "Please enter an expressionusing integers with each seporated by a space" << std::endl;
	std::string equation = "";
	std::getline(std::cin, equation);
	calculate(equation);
}

void Calculator::calculate(std::string equation){
	//keeps track of the number of open parenthesis
	int numOpenPar(0);
	std::stringstream function(equation);
	std::string read = "";
	bool nextNum = 1; 
	while(function >> read){
		if(!read.compare("(") || !read.compare(")")){
			if(Parentheses(read, numOpenPar, nextNum)){
				std::cout<<"Error invalid argumant with Parentheses"<<std::endl;
				clear();
				return;
			}
		}
		else{
			if(!read.compare("+") || !read.compare("-") || !read.compare("/") || !read.compare("%") || !read.compare("*")){
				if(nextNum){
					std::cout<<"Error invalid argumant"<<std::endl;
					clear();
					return;
				}
				//Command * Push = builder(read);
				stackInteract(builder(read));
				//delete Push;
				nextNum = !nextNum;
			}
			else{
				try{
					int num = std::stoi(read);
					if(!nextNum){
						std::cout<<"Error invalid argumant"<<std::endl;
						clear();
						return;
					}
					nextNum = !nextNum;
					numbers.push(factory.buildNum(num));
				}
				catch(std::invalid_argument const& ex){
					std::cout<<"Error invalid argumant"<<std::endl;
					clear();
					return;
				}
			}
		}
	}
	finalAns(numOpenPar);
}

bool Calculator::Parentheses(std::string par, int & num, bool nextNum){
	if(!par.compare("(")){
		if(!nextNum)
			return true;
		num++;
		Command * Push = factory.buildPar();
		expression.push(Push);
	}
	else if(!par.compare(")")){
		if(nextNum)
			return true;
		num--;
		if(num < 0){
			std::cout <<"Invalid Expression, Too many closing parenthesis" << std::endl;
			clear();
			return true;
		}
		while(expression.top()->getPriority() != -1){
		int ans = expression.top()->run(numbers);
		numbers.push(factory.buildNum(ans));
		delete expression.top();
		expression.pop();
		}
		delete expression.top();
		expression.pop();
	}
	return false;
}

Command * Calculator::builder(std::string function){
	if(!function.compare("+")){
		return factory.buildAdd();
	}
	else if(!function.compare("-")){
		return factory.buildSub();
	}
	else if(!function.compare("%")){
		return factory.buildMod();
	}
	else if(!function.compare("/")){
		return factory.buildDev();
	}
	else {
		return factory.buildMult();
	}
}

void Calculator::stackInteract(Command * toPush){
	if(expression.empty() || (expression.top()->getPriority() < toPush->getPriority()))
		expression.push(toPush);
	else{
		int num = expression.top()->run(numbers);
		numbers.push(factory.buildNum(num));
		delete expression.top();
		expression.pop();
		expression.push(toPush);
	}
}

void Calculator::finalAns(int numOpenPar){
	if(numOpenPar != 0){
		std::cout << "Invalid Expression" << std::endl;
		clear();
	}
	while(!expression.empty()){
		int num = expression.top()->run(numbers);
		numbers.push(factory.buildNum(num));
		delete expression.top();
		expression.pop();
	}
	std::cout << "Your Answer is: " << numbers.top()->run(numbers) << std::endl;
	clear();
}


void Calculator::clear(){
	while(!expression.empty()){
		delete expression.top();
		expression.pop();
	}
	while(!numbers.empty()){
		delete numbers.top();
		numbers.pop();
	}
}

