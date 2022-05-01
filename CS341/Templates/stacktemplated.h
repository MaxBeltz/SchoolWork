#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack {
	private:
		int size;//maximum copasity of the stack
		T * data;//pointer to the internal array for the stack
		int top;//this int tells me which array position in data is the top
	public:
		//this constructor creates a one parameter constructor, however if no parameter is given will assume size of 10
		Stack(int = 10);//the default constructor with a default size of 10		
		~Stack();//we will have to specify this
		
		//this const means the function cannot change anything in the class
		bool isEmpty() const{return top == -1;}
		bool isFull() const {return top == size-1;}
		
		//the actual meaty functions
		bool pop(T&);//pop an element off the stack
		bool push(const T&);//push an element onto the stack
};



#endif