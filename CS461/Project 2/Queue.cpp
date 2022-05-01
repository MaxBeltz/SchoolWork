// I promise that the work submitted here is solely my own.
//
// mbeltz
// include the source file since template class


//
// Queue
//
template <typename T>
Queue <T>::Queue (void):end_(-1), information_(defaultSize)
{}

//
// Queue
//
// Dr. Ryan: Couldn't we just include this in the initialization list?
//fixed, used initialization list
template <typename T>
Queue <T>::Queue (const Queue & Queue):end_(Queue.information_.size()), information_(Queue.information_) {}

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
	if(end_ >= information_.size())
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
			information_.set(i,information_.get(i+1));
	}
	else 
		throw empty_exception();
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
// Dr. Ryan: This won't really "clear" the Queue. We need to 
// 			 resize the Queue back to 0.
//fixed, used resize
template <typename T>
void Queue <T>::clear (void)
{
	information_.resize(0);
	end_=-1;
}
