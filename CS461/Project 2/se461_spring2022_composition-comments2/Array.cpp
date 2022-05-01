// I promise that the work submitted here is solely my own.
//
// mbeltz
#include <stdexcept>         // for std::out_of_bounds exception


//
// Array
//
template <typename T>
Array <T>::Array (void) : cur_size_(defaultSize), data_(nullptr)
{
	cur_size_ = defaultSize;
	data_ = new T[cur_size_];
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length): cur_size_(defaultSize), data_(nullptr)
{
	cur_size_ = length;
	data_ = new T[cur_size_];
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill): cur_size_(defaultSize), data_(nullptr)
{
	cur_size_ = length;
	data_ = new T[cur_size_];
	this->fill(fill);
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array): cur_size_(defaultSize) , data_(nullptr)
{
	cur_size_ = array.cur_size_;
	data_ = new T[cur_size_];
	for(int i=0; i<cur_size_; i++)
		data_[i] = array.data_[i];
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	delete [] data_;
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	if(*this == rhs)
		return *this;
	bool resize = false;
	if(cur_size_ != rhs.cur_size_){
		cur_size_ = rhs.cur_size_;
		delete [] data_;
		data_ = new T[cur_size_];
	}
	for(int i = 0; i<rhs.cur_size_; i++)
		data_[i] = rhs.data_[i];
	return *this;
}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
	if (index > cur_size_)
		throw std::out_of_range("Index Out of Range");
	return data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
	if (index > cur_size_)
		throw std::out_of_range("Index Out of Range");
	return data_[index];
}

//
// get
//
template <typename T>
T Array <T>::get (size_t index) const
{
	if (index < cur_size_)
		return data_[index];
	else 
		throw std::out_of_range("Index Out of Range");
}

//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{
	if(index < cur_size_)
		data_[index] = value;
	else 
		throw std::out_of_range("Index Out of Range");
}

// Dr. Ryan: Note your resize method is gone here but still in the header.

//
// find (char)
//
template  <typename T>
int Array <T>::find (T value) const
{
	return find(value, 0);
}

//
// find (char, size_t) 
//
template <typename T>
int Array <T>::find (T val, size_t start) const
{
	if (start > cur_size_)
		throw std::out_of_range("Index Out of Range");
	for(int i = start; i< cur_size_; i++){
		if(data_[i] == val)
			return i;
	}
	return -1;
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
	if(this == &rhs)
		return true;
	if (cur_size_ != rhs.cur_size_)
		return false;
	for(int i=0; i<cur_size_; i++){
		if (data_[i] != rhs.data_[i])
			return false;
	}
	return true;
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
	bool returnval = (*this == rhs);
	return !returnval;
}

//
// fill
//
template <typename T>
void Array <T>::fill (T value)
{
	for(int i=0; i<cur_size_; i++)
		data_[i] = value;
}
