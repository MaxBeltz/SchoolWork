#include <iostream>
#include <math.h>
using namespace std;

class Rectangle {
	private: //default area
		//this area is reserved fro data and functions that are not supposed to be accessable outside of the class
		int w, h;
		int * unnecessary;
	
	public: //a place to stire interfaces ususally
		Rectangle() {} //default constructor
		Rectangle(int x, int y){
			w = x;
			h = y;
			unnecessary = new int[100000];
		}//end xy constructor
		
		//alternate way to declair constructors
		Rectangle(int x, int y, int * z) : w(x), h(y), unnecessary(new int[1000]) {};
		
		~Rectangle(); //when the class instance is finished clear the memory 
		int area();
		int perm();
	
	protected: //only this class, friends of this class, and derrived classes have access to these items
	
};//end class rectangel

Rectangle::~Rectangle{
	delete [] unnecessary;
}//end destructor
int Rectangle::area(){
	return w * h;
}//end area
int Rectangle::perm(){
	return 2*w + 2*h;
}//end perm

int main(){
	//driver program
	Ractangle myRect(15, 10);
	
	//another way to create a class
	Rectangle * pointToMyRect = new Rectangle(20,20);
	
	cout << mrRect.area() << endl;
	cout << (*pointToMyRect).area() << endl;
	cout << pointToMyRect->area() << enld;
	
	delete pointToMyRect;
	
	return 0;
}