#include "employee.h"

int Employee::count = 0;

Employee::Employee():birthDay(0),birthMonth(0),birthYear(0){
	firstName = "";
	lastName = "";
	nickName = "";
	//cant explicitly set these values as they are const. 
	//birthDay = 0;
	//birthMonth = 0;
	//birthYear = 0;
	
	hireDay = 0;
	hireMonth = 0;
	hireYear = 0;
	count++;
}

Employee::~Employee(){
	count--;
}

void Employee::printInfo(){
	cout << getName() << endl;
	cout << " Born on:" << birthMonth << "/" << birthDay << "/" << birthYear;
	cout << "Hired on:" << hireMonth << "/" << hireDay << "/" << hireYear;
}

//setNichName is a friend function of class employee
void setNickName(Employee & buddy,string n){
	buddy.nickName = n;
}
