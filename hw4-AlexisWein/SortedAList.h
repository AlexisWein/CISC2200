#ifndef __SORTED_ALIST_H__
#define __SORTED_ALIST_H__

#include "SortedList.h"
#include <cassert>

namespace ds {

// Sorted array list implementation
template <typename E> class SortedAList : public SortedList<E> {
private:
  int maxSize;  // Maximum size of list
  int listSize; // Number of list items now
  int curr;     // Position of current element
  E *listArray; // Array holding list elements

public:
  SortedAList(int size = 10) { // Constructor
    maxSize = size;
    listSize = curr = 0;
    listArray = new E[maxSize];
  }

  // Constructor only to facilitate autograding
  SortedAList(int size, E vals[]) {
    maxSize = 10;
    listSize = size;
    curr = 0;
    listArray = new E[maxSize];
    for (int i = 0; i < size; i++) {
      listArray[i] = vals[i];
    }
  }

  ~SortedAList() { delete[] listArray; } // Destructor

  void clear() {                // Reinitialize the list
    delete[] listArray;         // Remove the array
    listSize = curr = 0;        // Reset the size
    listArray = new E[maxSize]; // Recreate array
  }

  // Remove and return the current element.
  E remove() {
    assert((curr >= 0) && (curr < listSize));
    E it = listArray[curr];                   // Copy the element
    for (int i = curr; i < listSize - 1; i++) // Shift them down
      listArray[i] = listArray[i + 1];
    listSize--; // Decrement size
    return it;
  }

  // Reset position
  void moveToStart() { curr = 0; }

  // Set at end
  void moveToEnd() { curr = listSize; }

  // Back up
  void prev() {
    if (curr != 0)
      curr--;
  }

  // Next
  void next() {
    if (curr < listSize)
      curr++;
  }

  // Return list size
  int length() const { return listSize; }

  // Return current position
  int currPos() const { return curr; }

  // Set current list position to "pos"
  void moveToPos(int pos) {
    assert((pos >= 0) && (pos <= listSize));
    curr = pos;
  }

  // Return current element
  const E &getValue() const {
    assert((curr >= 0) && (curr < listSize));
    return listArray[curr];
  }

  void putElement(const E &it);
};

template <typename E> void SortedAList<E>::putElement(const E &it) {
  // TODO: put element "it" into the sorted array list
  
  listSize++;                               //increases the list size so we know we're working with a lost that has at least 1 element
  for(int j = listSize-1; j >= 0; j--)      //iterates through the list backwards to find the right insertion position
  {
    if(j != 0 && listArray[j-1] > it)       //moves elements over to make room for it
    {
      listArray[j] = listArray[j-1];
    }
    else
    {
      listArray[j] = it;
      j = -1;                               //acts as a break statement
    }        
  }
}

} // namespace ds

#endif // __SORTED_ALIST_H__