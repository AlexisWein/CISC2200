#ifndef __SORTED_LLIST_H__
#define __SORTED_LLIST_H__

#include "Link.h"
#include "SortedList.h"
#include <cassert>

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

  // Destructor
  ~SortedLList() { removeall(); }

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

  void putElement(const E &it);
};

template <typename E> void SortedLList<E>::putElement(const E &it) {
  // TODO: put element "it" into the sorted linked list
  Link<E> *temp = new Link<E>;          //creates a new node to store it
  temp->element = it;                   //assigns the new node to the value of it
  temp->next = NULL;                    //temp is not pointing to an element in the list yet, so make it point to NULL
  
  cnt++;                                //increases the size of the list so we know we're working with a list of at least 1 element
  if(head->next == NULL)                //inserts it into the list if the list is empty
  {
    temp->next = head->next;            //makes temp->next point to the same element as head->next, which is NULL in this case
    head->next = temp;                  //reassigns head->next to point to temp, which is now the first element
    tail = temp;                        //sets the tail to temp, because temp is the only element in the list
  }
  else if(head->next->element >= temp->element)     //inserts it at the beginning of the list if the first element is larger than it, similar to the prepend function in lab3
  {
    temp->next = head->next;
    head->next = temp;
  }
  else
  {
    while(curr->next != NULL  &&  curr->next->element <= temp->element)       //moves curr through the linked list to find the right insertion position
    {
      curr = curr->next;
    }
    temp->next = curr->next;          //sets temp->next to curr->next when the while loop finds an element greater than (>) temp
    curr->next = temp;
    curr = head;                      //moves the current element cursor back to the beginning
  }
  while(curr->next != NULL)           //moves through the list to find the last element
  {
    curr = curr->next;
  }
  tail = curr;                        //sets the tail equal to the last element, which is curr after the loop
  curr = head;                        //moves the cursor back to the beginning
  
}

} // namespace ds

#endif // __SORTED_LLIST_H__