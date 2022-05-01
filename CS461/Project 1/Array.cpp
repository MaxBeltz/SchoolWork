// I promise that the work submitted here is solely my own.
//
// mbeltz

#include "Array.h"

const int defaultsize = 10;
//global const

// Dr. Ryan: We should use an initilization list here for our constructors.
//Added initialization list to all constructors
Array::Array (void): cur_size_(defaultsize), max_size_(defaultsize*1.5), data_(nullptr)
{
	// Dr. Ryan: Numerical literals are dangerous as they are hard coded and
	//			 require multiple changes - instead why not leverage global
	//			 constants.
	//Created global const default size
	cur_size_ = defaultsize;
	max_size_ = defaultsize*1.5;
	data_ = new char[max_size_];
}

Array::Array (size_t length): cur_size_(defaultsize), max_size_(defaultsize*1.5), data_(nullptr)
{
	max_size_ = length * 1.5;
	cur_size_ = length;
	data_ = new char[max_size_];
}

Array::Array (size_t length, char fill): cur_size_(defaultsize), max_size_(defaultsize*1.5), data_(nullptr)
{
	max_size_ = length * 1.5;
	cur_size_ = length;
	data_ = new char[max_size_];
	// Dr. Ryan: Good use of code reuse!
	this->fill(fill);
}

Array::Array (const Array & array): cur_size_(defaultsize), max_size_(defaultsize*1.5), data_(nullptr)
{
	cur_size_ = array.cur_size_;
	max_size_ = array.max_size_;
	data_ = new char[max_size_];
	for(int i=0; i<cur_size_; i++)
		data_[i] = array.data_[i];
}

Array::~Array (void)
{
	delete [] data_;
}

const Array & Array::operator = (const Array & rhs) 
{
	// Dr. Ryan: Always check for self-assignment first.
	// added this if statement
	if(*this == rhs)
		return *this;
	// Dr. Ryan: What if the sizes are the same?
	// Only change cur_size_ if different
	// Only change max_size_ and create a new array if different
	bool resize = false;
	if(cur_size_ != rhs.cur_size_)
		cur_size_ = rhs.cur_size_;
	if(max_size_ != rhs.max_size_){
		max_size_ = rhs.max_size_;
		delete [] data_;
		data_ = new char[max_size_];
	}
	for(int i = 0; i<rhs.cur_size_; i++)
		data_[i] = rhs.data_[i];
	return *this;
}

// Dr. Ryan: Can't we leverage the get function for the two 
//			 operator overloads?
//returning seg fault when accessing get function
//told by email that this comment can be ignored
char & Array::operator [] (size_t index)
{
	if (index > cur_size_)
		throw std::out_of_range("Index Out of Range");
	return data_[index];
}

const char & Array::operator [] (size_t index) const
{
	if (index > cur_size_)
		throw std::out_of_range("Index Out of Range");
	return data_[index];
}

char Array::get (size_t index) const
{
	if (index < cur_size_)
		return data_[index];
	else 
		throw std::out_of_range("Index Out of Range");
}

void Array::set (size_t index, char value)
{
	if(index < cur_size_)
		data_[index] = value;
	else 
		throw std::out_of_range("Index Out of Range");
}

void Array::resize (size_t new_size)
{
	if (new_size <= max_size_)
		cur_size_  = new_size;
	else{
		char temp[new_size];
		for (int i=0; i<cur_size_; i++)
			temp[i] = data_[i];
		delete [] data_;
		data_ = new char[new_size];
		for(int i=0; i<cur_size_; i++)
			data_[i] = temp[i];
		cur_size_ = new_size;
		max_size_ = new_size * 1.5;
	}
}

int Array::find (char ch) const
{
	// Dr. Ryan: Excellent!!!!!
	return find(ch, 0);
}

int Array::find (char ch, size_t start) const
{
	if (start > cur_size_)
		throw std::out_of_range("Index Out of Range");
	for(int i = start; i< cur_size_; i++){
		if(data_[i] == ch)
			return i;
	}
	return -1;
}

bool Array::operator == (const Array & rhs) const
{	
	// Dr. Ryan: Always check for self-comparison first.
	//fixed, added self check
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

bool Array::operator != (const Array & rhs) const
{
	// Dr. Ryan: Why not just call the equality operator and negate it?
	//Fixed, added return val to remove erroring
	bool returnval = (*this == rhs);
	return !returnval;
}

void Array::fill (char ch)
{
	for(int i=0; i<cur_size_; i++)
		data_[i] = ch;
}