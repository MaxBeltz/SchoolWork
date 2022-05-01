// I promise that the work submitted here is solely my own.
//
// mbeltz
// include the source file since template class
#include "Stack.h"

//
// Stack
//
template <typename T>
Stack <T>::Stack (void):top_(-1), information_(defaultSize)
{
	top_=-1;
	information_(defaultSize);
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack):top_(-1), information_(stack) {}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void) {}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	top_++;
	if(top_ >= information_.cur_size)
		information_.resize(information_.cur_size+1);
	information_[top_] = element;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	if(!is_empty())
		top_--;
	else 
		throw empty_exception("Empty Stack");
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	this.information_=rhs.information_;
	this.top_=rhs.top_;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	top_=-1;
}
