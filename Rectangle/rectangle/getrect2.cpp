#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

#include "rectangle.cpp"




/*int Square::area() {
	return side*side;
}//end area square
int Square::perm() {
	return 4*side;
}//end perm square */

int main(){
	//driver program
	
	//fstream is a class that manages file i/oct
	//it contains three classes: fstram, ifstream, ofstream
	
	istream fin;
	fin.open("shapearray.txt");
	
	int asize; 
	fin >> asize;
	
	Rectangle * rectarray = new Rectangle[asize]
	for (int x = 0; x < asize; x++){
		fin >> rectarray.w >> rectarray.h;
	
	return 0;
}