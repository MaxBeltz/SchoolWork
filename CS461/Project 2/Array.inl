// I promise that the work submitted here is solely my own.
//
// mbeltz
//
// size
//
template <typename T>
inline
size_t Array <T>::size (void) const
{
	return cur_size_;
}
// Dr. Ryan: We don't want max_size_ here anymore as this is the base
// class and Fixed Array's won't have a max_size_
// fixed

