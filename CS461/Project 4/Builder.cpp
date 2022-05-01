// I promise that the work submitted here is solely my own.
//
// mbeltz

#include "Builder.h"

Builder::Builder() : Tree(), Expression() {}

Builder::~Builder() {}

Node * Builder::build(std::string expression) {
	std::stringstream function(expression);
	std::string read = "";
	bool nextNum = 1; 
	while(function >> read){
		//std::cout<<read<<std::endl;
		if(!read.compare("+") || !read.compare("-") || !read.compare("/") || !read.compare("%") || !read.compare("*")){
			if(nextNum){
				std::cout<<"Error invalid argumant"<<std::endl;
				return new NodeNum();
			}
			NodeBio * comm = new NodeBio;
			comm = treeInteract(read);
			nextNum = !nextNum;
			if(Expression.empty())
				Expression.push(comm);
			else if (Expression.top()->getPriority() < comm->getPriority())
				Expression.push(comm);
			else{
				while(!Expression.empty() && Expression.top()->getPriority() > comm->getPriority())
					PopConnectPush();
				Expression.push(comm);
			}
		}
		else{
			try{
				int num = std::stoi(read);
				if(!nextNum){
					std::cout<<"Error invalid argumant"<<std::endl;
					return new NodeNum();
				}
				nextNum = !nextNum;
				NodeNum * toPush = buildNum(num);
				Tree.push(toPush);
			}
			catch(std::invalid_argument const& ex){
				std::cout<<"Error invalid argumant"<<std::endl;
				return new NodeNum();
			}
		}
	}
	while (!Expression.empty())
		PopConnectPush();
	return Tree.top();
}


NodeBio * Builder::treeInteract(std::string function){
	if(!function.compare("+")){
		return buildAdd();
	}
	else if(!function.compare("-")){
		return buildSub();
	}
	else if(!function.compare("%")){
		return buildMod();
	}
	else if(!function.compare("/")){
		return buildDev();
	}
	else {
		return buildMult();
	}
}


void Builder::PopConnectPush(){
	Node * N = Expression.top();
	Node * R = Tree.top();
	N->right = R;
	//delete Tree.top();
	Tree.pop();
	Node * L = Tree.top();
	N->left = L;
	//delete Tree.top();
	Tree.pop();
	Tree.push(N);
	//delete Expression.top();
	Expression.pop();
}

NodeAdd * Builder::buildAdd() {return new NodeAdd();}

NodeSub * Builder::buildSub() {return new NodeSub();}

NodeMult * Builder::buildMult() {return new NodeMult();}

NodeMod * Builder::buildMod() {return new NodeMod();}

NodeDev * Builder::buildDev() {return new NodeDev();}

NodeNum * Builder::buildNum(int val) {return new NodeNum(val);}
