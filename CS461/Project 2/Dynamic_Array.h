// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_

#include <cstring>          // for size_t definition
#include "Array.h"

/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
template <typename T>
class Dynamic_Array : public Array <T>
{
public:
  /// Type definition of the element type.
  typedef T type;

  /// Default constructor.
  Dynamic_Array (void);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   */
  Dynamic_Array (size_t length);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   * @param[in]      fill          Initial value for each element
   */
  Dynamic_Array (size_t length, T fill);

  /**
   * Copy constructor
   *
   * @param[in]     arr         The source array.
   */
  Dynamic_Array (const Dynamic_Array & arr);

  /// Destructor.
  ~Dynamic_Array (void);
  	  
	 /**
	 * Retrieve the maximum size of the array.
	 *
	 * @return          The maximum size
	 */
	size_t max_size (void) const;

  /**
   * Assignment operation
   *
   * @param[in]       rhs      Right-hand side of equal sign
   * @return          Reference to self
   */
  const Dynamic_Array & operator = (const Dynamic_Array & rhs);


  /**
   * Set a new size for the array. If \a new_size is less than the current
   * size, then the array is truncated. If \a new_size if greater then the
   * current size, then the array is made larger and the new elements are
   * not initialized to anything. If \a new_size is the same as the current
   * size, then nothing happens.
   *
   * The array's original contents are preserved regardless of whether the 
   * array's size is either increased or decreased.
   *
   * @param[in]       new_size              New size of the array
   */
  void resize (size_t new_size);

  /**
   * Test the array for equality.
   *
   * @param[in]       rhs                  Right hand side of equal to sign
   * @retval          true                 Left side is equal to right side
   * @retval          false                Left side is not equal to right side
   */
  bool operator == (const Dynamic_Array & rhs) const;

  /**
   * Test the array for inequality.
   *
   * @param[in]       rhs                  Right-hand size of not equal to sign
   * @retval          true                 Left side is not equal to right side
   * @retval          false                Left size is equal to right side
   */
  bool operator != (const Dynamic_Array & rhs) const;


// Dr. Ryan: We only need max_size_ here as the others should come from our base class.
// fixed
private:
	/// Maximum size of the array.
    size_t max_size_;
};

#include "Dynamic_Array.inl"
#include "Dynamic_Array.cpp"

#endif   // !defined _ARRAY_H_
