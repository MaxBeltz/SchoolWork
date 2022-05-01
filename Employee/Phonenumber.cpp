#include <iomanip>
using namespace std;
#include <phonenumber.h>

ostream & operator<<(ostream & out, const Phonenumber & num){
	out << "(" << num.areaCode << ") " << num.exchange << "-" << num.line;
	return out;
}

istream & operator>>(istream & in, Phonenumber & num){
	in.ignore(); //skip (
	in >> setw(3) >> num.areaCode;
	in.ignore(2); //skip ) and space
	in >> setw(3) >> num.exchange;
	in.ignore() //skips -
	in >> setw(4) >> num.line;
	return in;
}