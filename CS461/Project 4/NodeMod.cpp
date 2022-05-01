// I promise that the work submitted here is solely my own.
//
// mbeltz
#include "NodeMod.h"
NodeMod::NodeMod(){}


int NodeMod::getPriority() {return 3;}


int NodeMod::visit(Visitor & v) {return v.VisitMod(*this); }