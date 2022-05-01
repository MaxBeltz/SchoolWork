// I promise that the work submitted here is solely my own.
//
// mbeltz
#include "NodeAdd.h"
NodeAdd::NodeAdd(){}

NodeAdd::~NodeAdd() {}

int NodeAdd::getPriority() {return prior;}

int NodeAdd::visit(Visitor & v) {return v.VisitAdd(*this); }