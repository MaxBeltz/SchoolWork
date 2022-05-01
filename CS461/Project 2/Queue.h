// I promise that the work submitted here is solely my own.
//
// mbeltz
#ifndef _Queue_H_
#define _Queue_H_

#include <exception>
#include "Dynamic_Array.h"

/**
 * @class Queue
 *
 * Basic Queue for abitrary elements.
 */
template <typename T>
class Queue
{
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the Queue is empty.
   */
  class empty_exception : public std::exception
  {
  public:
    /// Default constructor.
    empty_exception (void)
      : std::exception () { }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    empty_exception (const char * msg)
      : std::exception (msg) { }
  };

  /// Default constructor.
  Queue (void);

  /// Copy constructor.
  Queue (const Queue & s);

  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue & operator = (const Queue & rhs);

  /**
   * Push a new \a element onto the Queue. The element is inserted
   * before all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void enqueue (T element);

  /**
   * Remove the top-most element from the Queue.
   *
   * @exception      empty_exception    The Queue is empty.
   */
  void dequeue (void);
  
    /**
   * Get the next element on the Queue. If there are no element 
   * on the queue, then the queue_is_empty exception is thrown.
   *
   * @return         Element on top of the stack.
   * @exception      empty_exception    The Queue is empty
   */
  T next (void) const;

  /**
   * Test if the Queue is empty
   *
   * @retval         true          The Queue is empty
   * @retval         false         The Queue is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the Queue.
   *
   * @return         Size of the Queue.
   */
  size_t size (void) const;

  /// Remove all elements from the Queue.
  void clear (void);

private:
	//the Actual data of the Array
	Dynamic_Array <T> information_;
	
	//the int position of the current end of line
	int end_;
	
	//used for default size calculations
	const int defaultSize = 10;
};

// include the inline files

#include "Queue.inl"
#include "Queue.cpp"


#endif   // !defined _Queue_H_