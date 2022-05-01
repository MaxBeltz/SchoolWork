#ifndef PIRATE_H
#define PIRATE_H

#include <iostream>
#include <string>
using namespace std;

// You need to apply some care when building the .cpp, but the .h SHOULD (;) need to change.
class Pirate {
    public:
        string name;                    // pirate's name
        unsigned int height;            // height of the pirate
        int numLimbos;                  // number of successful limbo 
        static int numDead;
        
        // Basic class setup
        Pirate();
        ~Pirate();
        
        bool canLimbo(int h) {return height <= h;}
        void print() {cout << name << " " << height << " " << numLimbos << endl;}
};

#endif