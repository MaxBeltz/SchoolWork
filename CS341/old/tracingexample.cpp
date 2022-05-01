#include <iostream>
#include <math.h>
using namespace std;

int c (int &, int);

int main () {
	int s = 2, r = 4;
	
	cout << c(s,r) << endl;
	cout << s << endl;
	cout << r << endl;
	
	return 0
}

int c(int &w, int q) {
	w++;
	retuen w + q;
}