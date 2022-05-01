// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _VISITOR_H_
#define _VISITOR_H_

class NodeNum;
class NodeAdd;
class NodeDev;
class NodeSub;
class NodeMult;
class NodeMod;

class Visitor{
	public:
	Visitor() {};
	
	virtual ~Visitor() {};
	
	virtual int VisitNum(NodeNum N) = 0;
	virtual int VisitAdd(NodeAdd N) = 0;
	virtual int VisitDev(NodeDev N) = 0;
	virtual int VisitSub(NodeSub N) = 0;
	virtual int VisitMult(NodeMult N) = 0;
	virtual int VisitMod(NodeMod N) = 0;	
};
#endif