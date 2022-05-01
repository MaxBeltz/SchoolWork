#ifndef NODE_H
#define NODE_H

#include "pirate.h"

class Node {
    public:
        Pirate pirate;
        Node * next;
        Node * prev;
        
        // Basic class setup
        // You will need to define the default constructor/deconstructor
        Node();
        ~Node();
        Node(const Pirate & p) : pirate(p), next(NULL), prev(NULL) {}

};


#endif