// I promise that the work submitted here is solely my own.
//
// mbeltz
#include <stdexcept>         // for std::out_of_bounds exception

// Dr. Ryan: If we are using our base class - most of this code can be reduced to a call
//		     to the base class.
//fixed
//
// Dynamic_Array
//
template <typename T>
Dynamic_Array <T>::Dynamic_Array (void) : Array<T>(),  max_size_(Array <T>::defaultSize*1.5)
{
	delete Array <T>::data_ ;
	Array <T>::data_ = new T[max_size_];
}

//
// Dynamic_Array (size_t)
//
template <typename T>
Dynamic_Array <T>::Dynamic_Array (size_t length): Array<T>(length), max_size_(length*1.5)
{
	delete Array <T>::data_ ;
	Array <T>::data_ = new T[max_size_];
}

//
// Dynamic_Array (size_t, char)
//
template <typename T>
Dynamic_Array <T>::Dynamic_Array (size_t length, T fill): Array<T>(length, fill), max_size_(Array <T>::defaultSize*1.5)
{

	delete Array <T>::data_ ;
	Array <T>::data_ = new T[max_size_];
	this->fill(fill);
}

//
// Dynamic_Array (const Dynamic_Array &)
//
template <typename T>
Dynamic_Array <T>::Dynamic_Array (const Dynamic_Array & Arr): Array<T>(), max_size_(Array <T>::defaultSize*1.5)
{

	delete Array <T>::data_ ;
	Array <T>::data_ = new T[max_size_];
	for(int i=0; i<Array <T>::cur_size_; i++)
		Array <T>::data_[i] = Arr.data_[i];
}

//
// ~Dynamic_Array
//
template <typename T>
Dynamic_Array <T>::~Dynamic_Array (void) {}

//
// operator =
//
template <typename T>
const Dynamic_Array <T> & Dynamic_Array <T>::operator = (const Dynamic_Array & rhs)
{
	if(*this == rhs)
		return *this;
	bool resize = false;
	if(Array <T>::cur_size_ != rhs.cur_size_)
		Array <T>::cur_size_ = rhs.cur_size_;
	if(max_size_ != rhs.max_size_){
		max_size_ = rhs.max_size_;
		delete [] Array <T>::data_;
		Array <T>::data_ = new T[max_size_];
	}
	for(int i = 0; i<rhs.cur_size_; i++)
		Array <T>::data_[i] = rhs.data_[i];
	return *this;
}

//
// resize
//
template <typename T>
void Dynamic_Array <T>::resize (size_t new_size)
{
	if (new_size <= max_size_)
		Array <T>::cur_size_  = new_size;
	else{
		T temp[new_size];
		for (int i=0; i<Array <T>::cur_size_; i++)
			temp[i] = Array <T>::data_[i];
		delete [] Array <T>::data_;
		Array <T>::data_ = new T[new_size];
		for(int i=0; i<Array <T>::cur_size_; i++)
			Array <T>::data_[i] = temp[i];
		Array <T>::cur_size_ = new_size;
		max_size_ = new_size * 1.5;
	}
}

//
// operator ==
//
template <typename T>
bool Dynamic_Array <T>::operator == (const Dynamic_Array & rhs) const
{
	if(this == &rhs)
		return true;
	if (Array <T>::cur_size_ != rhs.cur_size_)
		return false;
	for(int i=0; i<Array <T>::cur_size_; i++){
		if (Array <T>::data_[i] != rhs.data_[i])
			return false;
	}
	return true;
}

//
// operator !=
//
template <typename T>
bool Dynamic_Array <T>::operator != (const Dynamic_Array & rhs) const
{
	bool returnval = (*this == rhs);
	return !returnval;
}
