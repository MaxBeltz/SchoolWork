// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _VISITORCONCRETE_H_
#define _VISITORCONCRETE_H_

#include "Visitor.h"

#include "NodeMult.h"
#include "NodeDev.h"
#include "NodeMod.h"
#include "NodeAdd.h"
#include "NodeSub.h"
#include "NodeNum.h"

#include <iostream>

class VisitorConcrete : public Visitor{
	public:
	VisitorConcrete();
	
	~VisitorConcrete();
	
	int VisitNum(NodeNum N);
	int VisitAdd(NodeAdd N);
	int VisitDev(NodeDev N);
	int VisitSub(NodeSub N);
	int VisitMult(NodeMult N);
	int VisitMod(NodeMod N);
	
	int getResult();
	void calculateResult(Node * N);
	private:
		int result;
	
};
#endif