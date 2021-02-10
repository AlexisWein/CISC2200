#include "MinStack.h"

namespace ds {

MinStack::MinStack() {
  // TODO: initialize your data structure here
  minEle = 2147483647;            //initializes minEle to the largest possible int value so anything you compare against it will prpbably be smaller and won't be larger
}

void MinStack::push(int x) {
  // TODO: push element x onto stack
  if(x <= minEle)                 //pushes minEle to the stack before pushing x to the stack
  {
    internalStack.push(minEle);
    minEle = x;
  }
  internalStack.push(x);
}

void MinStack::pop() {
  // TODO: remove the element on top of the stack
  if(internalStack.top() == minEle)         //pops twice if the top == minEle
  {
    internalStack.pop();
    minEle = internalStack.top();           //sets minEle to the top of the stack before removing it
    internalStack.pop();
  }
  else
  {
    internalStack.pop();                    //pops once if the top of the stack != minEle
  }
  
  
}

int MinStack::top() {
  // TODO: get the top element
  return internalStack.top();
}

int MinStack::getMin() {
  // TODO: retrieve the minimum element in the stack
  return minEle;
}

} // namespace ds