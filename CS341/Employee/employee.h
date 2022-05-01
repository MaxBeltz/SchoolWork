#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;

class Employee{
	private:	//private is default for classes
		string firstName;
		string lastName;
		string nickName;
		const unsigned int birthDay;
		const unsigned int birthMonth;
		const unsigned int birthYear;
		
		unsigned int hireDay;
		unsigned int hireMonth;
		unsigned int hireYear;
		
		//a static variable is created for the class as a whole, not for each individual instance.
		//in other words Employee will have one copy of count shared across all instances of employee
		static int count;	//keeps track of total number of employees
	public:
		//boiler plate
		Employee();
		~Employee();
		
		//access function
		string getName(){return firstName + " " + lastName;}
		int getCount(){return count;}
		void setName(strin f, string l) {firstName = f; lastName = l;}
		void setHire(int m, int d, int y) {hireMonth = m; hireDay = d; hireYear = y;}
		
		//utility functions
		void printInfo();
		
		//friend function
		friend void setNickName(string n) {nickName = n;}
};
#endif