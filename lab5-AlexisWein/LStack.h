#ifndef __LSTACK_H__
#define __LSTACK_H__

// Include the link class
#include "Link.h"

// First, get the declaration for the base stack class
#include "Stack.h"

namespace ds {
// This is the declaration for LStack.
// Linked stack implementation
template <typename E> class LStack : public Stack<E> {
private:
  Link<E> *top; // Pointer to first element
  int size;     // Number of elements

public:
  // Constructor
  LStack() {
    top = NULL;
    size = 0;
  }

  ~LStack() { clear(); } // Destructor

  void clear() {          // Reinitialize
    while (top != NULL) { // Delete link nodes
      Link<E> *temp = top;
      top = top->next;
      delete temp;
    }
    size = 0;
  }

  void push(const E &it) { // Put "it" on stack
    top = new Link<E>(it, top);
    size++;
  }

  E pop() { // Remove "it" from stack
    assert(top != NULL);
    E it = top->element;
    Link<E> *ltemp = top->next;
    delete top;
    top = ltemp;
    size--;
    return it;
  }

  const E &topValue() const { // Return top value
    assert(top != 0);
    return top->element;
  }

  int length() const { return size; } // Return length
};
} // namespace ds

#endif // __LSTACK_H__