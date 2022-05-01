#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <math.h>
using namespace std;



class Rectangle {
	private: //default area
		//this area is reserved fro data and functions that are not supposed to be accessable outside of the class
		int w, h;
	
	public: //a place to stire interfaces ususally
		Rectangle(); //default constructor
		Rectangle (int x, int y);//end xy constructor
		
		//alternate way to declair constructors
		
		virtual int area();
		virtual int perm();
		virtual void print();

	
};//end class rectangle


#endif