#include "stacktemplated.h"

template<typename T>
Stack<T>::Stack(int s){
	if (s > 0)
		size = s;
	else
		size = 10;
	top = -1;
	data = new T[size];
}

//ternary operator -- operators that work on 3 args
//alternate definition
//Stack<T>::Stack(int s) : top(-1), size(s > 0 ? s : 10), data(new T[size]){};

template<typename T>
Stack<T>::Stack() {
	delete [] data
};


template<typename T>
bool Stack<T>::push(const T & pushValue){
	if(isFull())
		return false;
	data[++top] = pushValue;
	return true;
}

//this uses laze deletion which is a key CS concept
template<typename T>
bool Stack<T>::pop(T & popLocation){
	if (isEmpty())
		return false;
	popLocation = data[top--];
	return true;
}