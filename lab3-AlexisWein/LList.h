#ifndef __LLIST_H__
#define __LLIST_H__

#include "Link.h"
#include "List.h"
#include <cassert>

namespace ds {

// Linked list implementation
template <typename E> class LList : public List<E> {
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
  LList(int size = defaultSize) { init(); }

  // Destructor
  ~LList() { removeall(); }

  // Clear list
  void clear() {
    removeall();
    init();
  }

  // Insert "it" at current position
  void insert(const E &it) {
    curr->next = new Link<E>(it, curr->next);
    if (tail == curr)
      tail = curr->next; // New tail
    cnt++;
  }

  // Append "it" to list
  void append(const E &it) {
    tail = tail->next = new Link<E>(it, NULL);
    cnt++;
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

  void prepend(const E &it);
  E removeFirst();
  E removeLast();
  void removeElement(const E &it);
  void reverse();
  void fill(const E &it);
};

template <typename E> void LList<E>::prepend(const E &it) {
  // TODO: insert "it" at the front of list
  head->next = new Link<E>(it, head->next);
  if(tail == curr)
  {
    tail = curr->next;
  }
  cnt++;
}

template <typename E> void LList<E>::fill(const E &it)
{
  curr = head;
  while(curr->next != NULL)
  {
    Link<E>  *temp = curr->next;
    curr->next = new Link<E>(it, curr->next);
    delete temp;
    curr = curr->next;
  }
  tail = curr;
  
}

template <typename E> E LList<E>::removeFirst() {
  // TODO: remove and return the first element

  E it = head->next->element;     //remember the value of head so you can return it
  Link<E> *temp = head->next;     //remember link node
  head->next = head->next->next;  //remove head from list
  delete temp;                    //reclaim space taken up by temp
  cnt--;                          //decrease the list size (the count)
  
  //cout << it << endl;           //debugging statement to check the value of it

  return it;
}

template <typename E> E LList<E>::removeLast() {
  // TODO: remove and return the last element
  
  //cout << "Test1" << endl;        //debugging statement
  E it = tail->element;             //remember value of tail so you can return it
  //cout << "Test2" << endl;        //debugging statement

  //cout << "tail: " << tail->element << endl;    //debugging statement to check the value of tail
  curr = tail;
  prev();
  //cout << "Curr: " << curr->element << endl;    //debugging statement
  delete curr->next;
  curr->next = NULL;
  tail = curr;
  cnt--;
  curr = head;

  //cout << it;                     //debugging statement to check the value of it
  
  return it;
}

template <typename E> void LList<E>::removeElement(const E &it) {
  // TODO: remove all instances of "it" in the list

  //cout << getValue() << endl;               //debugging statement to check the value of curr
  
  //while loop to remove all instances of it
  curr = head;
  while(curr->next != NULL)
  {
    //cout << "Test 1" << endl;                     //debugging statement
    if (it == curr->next->element)
    {
      //cout << it << endl;                         //debugging statement
      //cout << curr->next->element << endl;        //debugging statement
      Link<E> *temp = curr->next;                   //temp to hold the node being deleted
      //cout << "Temp Before: " << temp->element;   //debugging statement
      curr->next = curr->next->next;                //remove it from list
      delete temp;                                  //delete the node
      //cout << "Temp After: " << temp->element;    //debugging statement
      cnt--;                                        //decrement the count
    }

    else
    {
      curr = curr->next;                        //give curr a new value so the loop can keep running
    }
    //cout << getValue() << endl;             //debugging statement to check the value of curr
  }
  tail = curr;

}

template <typename E> void LList<E>::reverse() {
  // TODO: reverse the linked list
  //cout << "Test" << endl;                               //debugging statement
  Link<E> *previous = NULL;
  Link<E> *temp = head;

  curr = head->next;
  tail = head->next;
  while(curr != NULL)
  {
    //cout << "Test2" << endl;                            //debugging statement
    //cout << "current: " << current->element << endl;    //debugging statement
    //cout << "temp before : " << temp->element << endl;  //debugging statement
    temp = curr->next;
    //cout << "temp after : " << temp->element << endl;   //debugging statement
    curr->next = previous;
    previous = curr;
    curr = temp;
  }
  head->next = previous;
  moveToStart();
}

} // namespace ds

#endif // __LLIST_H__