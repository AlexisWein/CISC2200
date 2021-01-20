#include "AList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * This file was used only to run my own test cases on the assignment
 **/
int main(int argc, char *argv[]) {
  // You could write your own tests here, but they will not be used for autograding.
  
  // Below is an example. You should try to modify the statements to test the 5 methods.
  
  // >>> example begins <<<
  ds::AList<int> l;
  // My own test case
  l.append(0);
  l.append(1);
  l.append(2);
  l.append(3);
  l.append(4);
  l.append(5);
  /*l.append(5);
  l.append(4);
  l.append(5);
  l.append(6);
  */
 //8 1 2 3 3 4 1 5 3 3

  //l.append(8);
  //l.append(1);
  //l.append(0);
  /*l.append(3);
  l.append(3);
  l.append(4);
  l.append(1);
  l.append(5);
  l.append(3);
  l.append(3);*/


  /*srand(time(0));                // setting the seed for rand()
  for (int i = 0; i < 20; i++) { // append the list for 20 times
    l.append(rand() % 10 + 1);   // generating random numbers by rand()
  }*/

  cout << "Before: " << endl;
  ds::printList(l);
  cout << endl;
  

  l.fill(1);
  //l.removeFirst();
  //l.removeLast();
  //l.prepend(0);
  //l.removeElement(2);          //used to test my code

  cout << "After: " << endl;
  ds::printList(l);
  cout << endl;
  // >>> example ends <<<

  // DO NOT commit your changes of this file.
  // It is used just for your own tests.

  return 0;
}
