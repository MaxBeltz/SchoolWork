#ifndef LICORICE_H
#define LICORICE_H
using namespace std;
#include <stdlib.h> 
#include <time.h>  
#include <string>   

class LichorIce {
    private:
        int shatter;
        int weapon;
        string name = "";
    
    public:
        LichorIce(){shatter = 0; weapon = 0; name = "";}

        int getShatter() {return shatter;}
        int getWeapon() {return weapon;}
        string getName() {return name;}

        void setShatter(int val) {shatter = val;}
        void setWeapon(int val) {weapon = val;}
        void setName(string val) {name = val;}

        int shoot(){srand (time(NULL)); return (rand() % (weapon -1) + 1);}
};


#endif