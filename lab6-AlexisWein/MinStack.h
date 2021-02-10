#ifndef __MINSTACK_H__

#include <stack>

using std::stack;

namespace ds {

class MinStack {
private:
  // TODO: define your data members here
  stack<int> internalStack;
  int minEle;

public:
  MinStack();
  void push(int x);
  void pop();
  int top();
  int getMin();

  int length() { return internalStack.size(); }
};

} // namespace ds

#endif // __MINSTACK_H__