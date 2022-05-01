// I promise that the work submitted here is solely my own.
//
// mbeltz
#include "NodeSub.h"
NodeSub::NodeSub() {}

// Dr. Ryan: We should really use a global constant in place of the (2).
//fixed
int NodeSub::getPriority() {return prior;}

int NodeSub::visit(Visitor & v) {return v.VisitSub(*this); }