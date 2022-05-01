// I promise that the work submitted here is solely my own.
//
// mbeltz

#ifndef _BUILDER_H_
#define _BUILDER_H_

#include "NodeMult.h"
#include "NodeDev.h"
#include "NodeMod.h"
#include "NodeAdd.h"
#include "NodeSub.h"
#include "NodeNum.h"
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>

class Builder {
	public:
	Builder();
	~Builder();
	
	Node * build(std::string expression);
	NodeBio * treeInteract(std::string function);
	
	


	private:
	NodeAdd * buildAdd();
	NodeSub * buildSub();
	NodeMult * buildMult();
	NodeMod * buildMod();
	NodeDev * buildDev();
	NodeNum * buildNum(int val);
	
	void PopConnectPush();
	
	std::stack <Node *> Tree;
	std::stack <Node *> Expression;
};

#endif 