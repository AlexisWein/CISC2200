#ifndef __ALIST_H__
#define __ALIST_H__

#include "List.h"
#include <algorithm>
#include <cassert>

namespace ds {

// The array-based list implementation
template <typename E> class AList : public List<E> {
private:
  int maxSize;  // Maximum size of list
  int listSize; // Number of list items now
  int curr;     // Position of current element
  E *listArray; // Array holding list elements

public:
  AList(int size = defaultSize) { // Constructor
    maxSize = size;
    listSize = curr = 0;
    listArray = new E[maxSize];
  }

  ~AList() { delete[] listArray; } // Destructor

  void clear() {                // Reinitialize the list
    delete[] listArray;         // Remove the array
    listSize = curr = 0;        // Reset the size
    listArray = new E[maxSize]; // Recreate array
  }

  // Insert "it" at current position
  void insert(const E &it) {
    // assert(listSize < maxSize);
    checkAndResize();
    for (int i = listSize; i > curr; i--) // Shift elements up
      listArray[i] = listArray[i - 1];    //   to make room
    listArray[curr] = it;
    listSize++; // Increment list size
  }

  void append(const E &it) { // Append "it"
    // assert(listSize < maxSize);
    checkAndResize();
    listArray[listSize++] = it;
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

  void moveToStart() { curr = 0; }      // Reset position
  void moveToEnd() { curr = listSize; } // Set at end

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

  void prepend(const E &it);
  E removeFirst();
  E removeLast();
  void removeElement(const E &it);
  void checkAndResize();
  void fill(const E &it);
};

template <typename E> void AList<E>::prepend(const E &it) {
  // TODO: prepend "it", that is, insert "it" at the front of "listArray"
  checkAndResize();
  for(int i = listSize; i > curr; i--)
  {
    listArray[i] = listArray[i-1];
  }
  listArray[curr] = it;
  listSize++;
}

template <typename E> void AList<E>::fill(const E &it)
{
  for(int i = 0; i < listSize; i++)
  {
    listArray[i] = it;
  }
}

template <typename E> E AList<E>::removeFirst() {
  // TODO: remove the first element in "listArray"
  assert((curr >= 0) && (curr < listSize));
  E it = listArray[curr];    //uses value at index 0
  for(int i = curr; i < listSize - 1; i++)
  {
    listArray[i] = listArray[i+1];
  }
    listSize--;
    return it;
}

template <typename E> E AList<E>::removeLast() {
  // TODO: remove the last element in "listArray"
  E it = listArray[listSize - 1];    //uses value at index of last item in array
  listSize--;
    return it;
}

template <typename E> void AList<E>::removeElement(const E &it) {
  // TODO: remove all instances of "it" in-place in "listArray"
  for(int i = 0; i < listSize; i++)
  {
    if(listArray[i] == it)
    {
      for(int j = i; j < listSize; j++)
      {
        listArray[j] = listArray[j+1];
      }
      listSize--;
      i--;
    }
  }
}

template <typename E> void AList<E>::checkAndResize() {
  if (listSize < maxSize)
    return;
  // TODO: double the size of "listArray" while keeping its content
  maxSize *= 2;
  E *newArray = new E[maxSize];
  //cout << "newArray: " << newArray;       //debugging statement
  for(int i = 0; i < listSize; i++)
  {
    newArray[i] = listArray[i];
    //cout << newArray[i];                  //debugging statement
  }
  delete[] listArray;
  listArray = newArray;
  //cout << "listArray: " << listArray;     //debugging statement
}

} // namespace ds

#endif // __ALIST_H__