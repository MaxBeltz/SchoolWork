// I promise that the work submitted here is solely my own.
//
// mbeltz
// include the source file since template class
#include "Queue.h"

//
// Queue
//
template <typename T>
Queue <T>::Queue (void):end_(-1), information_(defaultSize)
{
	end_=-1;
	information_(defaultSize);
}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue & Queue):end_(-1), information_(Queue) {}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void) {}

//
// push
//
template <typename T>
void Queue <T>::enqueue (T element)
{
	end_++;
	if(end_ >= information_.cur_size_)
		information_.resize(end_);
	information_[end_] = element;
}

//
// pop
//
template <typename T>
void Queue <T>::dequeue (void)
{
	if(!is_empty()){
		end_--;
		for (int i = 0; i<end_; i++)
			information_[i] = information_[i+1];
	}
	else 
		throw empty_exception("Empty Queue");
	// Dr. Ryan: Is this a Stack or Queue?
	//fixed
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	this.information_=rhs.information_;
	this.end_=rhs.end_;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
	end_=-1;
}
