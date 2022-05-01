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
size_t Queue <T>::size (void) const
{
	return end_+1;
}

//
// is_empty
//
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
	return (end_==-1);
}
template <typename T>
inline
T Queue <T>::next (void) const
{
	if(end_>-1)
		return information_.get(end_);
	else 
		throw empty_exception();
}
