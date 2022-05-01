#include "rectangle.h"

Rectangle::Rectangle(int x, int y) {
	w = x;
	h = y;
}

int Rectangle::area(){
	return w * h;
}//end area rectangle
int Rectangle::perm(){
	return 2*w + 2*h;
}//end perm rectangle
void Rectangle::print() {
	cout << "Width: " << w << endl << "Height: " << h << endl;
}	
void Rectangle::setw(int x){
	w = x
}
		void seth(int x);

