// Dr. Ryan: Missing Honor Pledge & Digital Signature
//fixed
// I promise that the work submitted here is solely my own.
//
// mbeltz
//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return top_+1;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	if(top_>-1)
		return information_[top_];
	else 
		throw empty_exception("Empty Stack");
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	return (top_==-1);
}
