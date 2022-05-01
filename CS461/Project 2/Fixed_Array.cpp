// Dr. Ryan: We need to leverage our base class here...the bulk of this code
//			 is redundent as it is already handled by our base class.
//fixed, leveraged base class
//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void):  Array<T>(N) {}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr): Array<T>(arr) {}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr): Array<T>(arr) {}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill): Array<T>(fill) {}


//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void) {}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	for (int i=0; i<N; i++)
		Array <T>::data_[i] =  rhs.data_[i];
	return *this;
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
	//had to use get here for some reason, no idea why 
	for (int i=0; i<(N<M?N:M); i++)
		Array <T>::data_[i] = rhs.get(i);
	return *this;
}
