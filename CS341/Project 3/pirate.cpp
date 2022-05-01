#include "pirate.h"
#include <iostream>
#include <string>

int Pirate::numDead = 0;
Pirate::Pirate() {
	name = "";
	height = 0;            // height of the pirate
    numLimbos = 0;                  // number of successful limbo 
}

Pirate::~Pirate() {}
