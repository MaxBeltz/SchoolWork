// I promise that the work submitted here is solely my own.
//
// mbeltz
#include "NodeDev.h"
NodeDev::NodeDev() {}

int NodeDev::getPriority() {return prior;}


int NodeDev::visit(Visitor & v) {return v.VisitDev(*this); }