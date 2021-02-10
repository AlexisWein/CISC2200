#ifndef __SORTED_LLIST_H__
#define __SORTED_LLIST_H__

#include "Link.h"
#include "SortedList.h"
#include <cassert>
#include <iostream>
#include <algorithm>

namespace ds {

// Sorted linked list implementation
template <typename E> class SortedLList : public SortedList<E> {
private:
  Link<E> *head; // Pointer to list header
  Link<E> *tail; // Pointer to last element
  Link<E> *curr; // Access to current element
  int cnt;       // Size of list

  void init() { // Intialization helper method
    curr = tail = head = new Link<E>;
    cnt = 0;
  }

  void removeall() { // Return link nodes to free store
    while (head != NULL) {
      curr = head;
      head = head->next;
      delete curr;
    }
  }

public:
  // Constructor; parameter size is used just to  keep the
  // calls to constructor the same for both AList and LList
  SortedLList() { init(); }

  // Copy constructor
  SortedLList(const SortedLList &other) {
    init();
    cnt = other.cnt;
    Link<E> *p = other.head->next;
    while (p != NULL) {
      tail->next = new Link<E>(p->element, NULL);
      tail = tail->next;
      p = p->next;
    }
  }

  // Destructor
  ~SortedLList() { removeall(); }

  // Constructor only to facilitate autograding
  SortedLList(int size, E vals[]) {
    init();
    cnt += size;
    for (int i = 0; i < size; i++) {
      tail->next = new Link<E>(vals[i], NULL);
      tail = tail->next;
    }
  }

  // Clear list
  void clear() {
    removeall();
    init();
  }

  // Remove and return current element
  E remove() {
    assert(curr->next != NULL);
    E it = curr->next->element;  // Remember value
    Link<E> *ltemp = curr->next; // Remember link node
    if (tail == curr->next)
      tail = curr;                 // Reset tail
    curr->next = curr->next->next; // Remove from list
    delete ltemp;                  // Reclaim space
    cnt--;                         // Decrement the count
    return it;
  }

  // Place curr at list start
  void moveToStart() { curr = head; }

  // Place curr at list end
  void moveToEnd() { curr = tail; }

  // Move curr one step left; no change if already at front
  void prev() {
    if (curr == head)
      return; // No previous element
    Link<E> *temp = head;
    // March down list until we find the previous element
    while (temp->next != curr)
      temp = temp->next;
    curr = temp;
  }

  // Move curr one step right; no change if already at end
  void next() {
    if (curr != tail)
      curr = curr->next;
  }

  // Return length
  int length() const { return cnt; }

  // Return the position of the current element
  int currPos() const {
    Link<E> *temp = head;
    int i;
    for (i = 0; curr != temp; i++)
      temp = temp->next;
    return i;
  }

  // Move down list to "pos" position
  void moveToPos(int pos) {
    assert((pos >= 0) && (pos <= cnt));
    curr = head;
    for (int i = 0; i < pos; i++)
      curr = curr->next;
  }

  // Return current element
  const E &getValue() const {
    assert(curr->next != NULL);
    return curr->next->element;
  }

  template <typename T>
  friend std::ostream &operator<<(std::ostream &os,
                                  const SortedLList<T> &list) {
    os << "< ";
    Link<E> *ptr = list.head->next;
    while (ptr != NULL) {
      os << ptr->element << " ";
      ptr = ptr->next;
    }
    os << ">";
    return os;
  }

  template <typename T>
  friend SortedLList<T> listIntersection(const SortedLList<T> &list1,
                                         const SortedLList<T> &list2);

  template <typename T>
  friend SortedLList<T> listUnion(const SortedLList<T> &list1,
                                  const SortedLList<T> &list2);
};

template <typename E>
SortedLList<E> listIntersection(const SortedLList<E> &list1,
                                const SortedLList<E> &list2) {
  // TODO: return the sorted list making up of common items from list1 and
  // list2, duplicate items should appear only once into the result list NOTE:
  // you can access the data members in list1 and list2 simply using the period,
  // for example list1.head and list2.cnt
  
  SortedLList<E> temp1 = list1;                                 //temp list to hold list1
  SortedLList<E> temp2 = list2;                                 //temp list to hold list2
  
  int tempArr[list1.length() + list2.length()];                 //temp array to hold the new list (passed as a parameter to a new SortedLList later)
  int arrCnt = 0;                                               //holds the count/index of elements in the array
  
  temp1.moveToStart();                                          //moves curr to start of temp1 before executing the loop
  while (temp1.curr->next != NULL)
  {
    //std::cout << "currPos 1 test: " << temp1.currPos() << std::endl;                      //debugging statement
    temp2.moveToStart();                                        //moves curr to start of temp2 before executing the loop
    while(temp2.curr->next != NULL)                             //the inner loop adds elements from list2 if that element also exists in list1
    {
      //std::cout << "currPos 2 test: " << temp2.currPos() << std::endl;                    //debugging statement
      //std::cout << "temp1 element test: " << temp1.curr->next->element << std::endl;      //debugging statement
      //std::cout << "temp2 element test: " << temp2.curr->next->element << std::endl;      //debugging statement
      
      if(temp1.curr->next->element == temp2.curr->next->element  
          &&  std::find(tempArr, tempArr + arrCnt, temp2.curr->next->element) == tempArr + arrCnt)        //if statement checks for duplicates using std::find
      {
        tempArr[arrCnt] = temp1.curr->next->element;
        //std::cout << "array test: " << tempArr[arrCnt] << std::endl;                      //debugging statement
        arrCnt++;
      }
      //temp2.next();
      temp2.curr = temp2.curr->next;
    }
    //temp1.next();
    temp1.curr = temp1.curr->next;
    //std::cout << "Testing: " << temp1.curr->element << std::endl;                         //debugging statement
  }
  SortedLList<E> intersection(arrCnt, tempArr);                  //creates a new SortedLList intersection to be returned
  return intersection;                                           //returns intersection
  
}

template <typename E>
SortedLList<E> listUnion(const SortedLList<E> &list1,
                         const SortedLList<E> &list2) {
  // TODO: return the sorted list making up of all items from list1 and list2,
  // duplicate items should appear only once into the result list
  // NOTE: you can access the data members in list1 and list2 simply using the
  // period, for example list1.head and list2.cnt
  
  SortedLList<E> temp1 = list1;                               //temp list to hold list1
  SortedLList<E> temp2 = list2;                               //temp list to hold list2
  
  int tempArr[list1.length() + list2.length()];               //temp array to hold the new list (passed as a parameter to a new SortedLList later)
  int arrCnt = 0;                                             //holds the count/index of elements in the array

  temp1.moveToStart();                                        //moves curr to start of temp1 before executing the loop
  while (temp1.curr->next != NULL)                            //this loop adds everything from the first list to the new list
  {
    if(std::find(tempArr, tempArr + arrCnt, temp1.curr->next->element) == tempArr + arrCnt)           //if statement to check for duplicates using std::find
    {
      tempArr[arrCnt] = temp1.curr->next->element;
      arrCnt++;
    }
    
    temp1.curr = temp1.curr->next;
  }

  temp2.moveToStart();                                         //moves curr to start of temp2 before executing the loop
  while (temp2.curr->next != NULL)                             //this loop adds everything from the second list to the new list, as long as there are no duplicates
  {
    if(std::find(tempArr, tempArr + arrCnt, temp2.curr->next->element) == tempArr + arrCnt)           //if statement to check for duplicates using std::find
    {
      tempArr[arrCnt] = temp2.curr->next->element;
      arrCnt++;
    }
    
    temp2.curr = temp2.curr->next;
  }
  std::sort(tempArr, tempArr + arrCnt);                         //sorts the array using std::sort (makes sure the numbers are in order before making a new SortedLList)

  SortedLList<E> listUnion(arrCnt, tempArr);                    //creates a new SortedLList listUnion to be returned
  return listUnion;                                             //returns listUnion

}

} // namespace ds

#endif // __SORTED_LLIST_H__