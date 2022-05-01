// I promise that the work submitted here is solely my own.
//
// mbeltz

#include "VisitorConcrete.h"

VisitorConcrete::VisitorConcrete(): result(0){}

VisitorConcrete::~VisitorConcrete(){}

int VisitorConcrete::VisitNum(NodeNum N) {return N.getValue();}

int VisitorConcrete::VisitAdd(NodeAdd N){
	//std::cout << "ADD" << std::endl;
	int x = N.left->visit(*this);
	int y = N.right->visit(*this);
	return x + y;
}

int VisitorConcrete::VisitDev(NodeDev N){
	//std::cout << "DEV" << std::endl;
	int x = N.left->visit(*this);
	int y = N.right->visit(*this);
	return x / y;
}

int VisitorConcrete::VisitSub(NodeSub N){
	//std::cout << "SUB" << std::endl;
	int x = N.left->visit(*this);
	int y = N.right->visit(*this);
	return x - y;
}

int VisitorConcrete::VisitMult(NodeMult N){
	//std::cout << "MULT" << std::endl;
	int x = N.left->visit(*this);
	int y = N.right->visit(*this);
	return x * y;
}

int VisitorConcrete::VisitMod(NodeMod N){
	//std::cout << "MOD" << std::endl;
	int x = N.left->visit(*this);
	int y = N.right->visit(*this);
	return x % y;
}

int VisitorConcrete::getResult(){return result;}

void VisitorConcrete::calculateResult(Node * N){result = N->visit(*this);}