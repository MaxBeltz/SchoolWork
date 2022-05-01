// I promise that the work submitted here is solely my own.
//
// mbeltz
#include "NodeMult.h"
NodeMult::NodeMult() {}

int NodeMult::getPriority() {return prior;}

int NodeMult::visit(Visitor & v) {return v.VisitMult(*this); }