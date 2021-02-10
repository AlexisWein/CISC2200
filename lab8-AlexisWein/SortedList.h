#ifndef __SORTEDLIST_H__
#define __SORTEDLIST_H__

namespace ds {

template <typename E> class SortedList {
private:
  void operator=(const SortedList &) {} // Protect assignment
  // SortedList(const SortedList &) {}     // Protect copy constructor
public:
  SortedList() {}          // Default constructor
  virtual ~SortedList() {} // Base destructor

  // Clear contents from the list, to make it empty.
  virtual void clear() = 0;

  // Remove and return the current element.
  // Return: the element that was removed.
  virtual E remove() = 0;

  // Set the current position to the start of the list
  virtual void moveToStart() = 0;

  // Set the current position to the end of the list
  virtual void moveToEnd() = 0;

  // Move the current position one step left. No change
  // if already at beginning.
  virtual void prev() = 0;

  // Move the current position one step right. No change
  // if already at end.
  virtual void next() = 0;

  // Return: The number of elements in the list.
  virtual int length() const = 0;

  // Return: The position of the current element.
  virtual int currPos() const = 0;

  // Set current position.
  // pos: The position to make current.
  virtual void moveToPos(int pos) = 0;

  // Return: The current element.
  virtual const E &getValue() const = 0;

  // Put element "it" into the sorted list
  //virtual void putElement(const E &it) = 0;
};

} // namespace ds

#endif // __SORTEDLIST_H__