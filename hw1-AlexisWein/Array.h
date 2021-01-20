#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <algorithm>
#include <cstddef>
//#include <iostream>    //used for debugging

//using std::cout;       //used for debugging

namespace ds {

// a wrapper around C++ built-in array
template <typename T> class Array {
public:
  int length;

  Array(int len) : length(len), storedArray(new T[length]) {}

  Array(const Array<T> &x) : length(x.length), storedArray(new T[x.length]) {
    std::copy(x.storedArray, x.storedArray + x.length, storedArray);
  }

  ~Array() {
    if (storedArray != NULL) {
      delete[] storedArray;
      storedArray = NULL;
    }
  }

  T &operator[](int i) { return storedArray[i]; }

  void reverse();

private:
  T *storedArray;
};

template <typename T> void Array<T>::reverse() {
  // TODO: reverse storedArray
  int j = length - 1;
  for(int i = 0; i < j; i++)
  {
      int temp = storedArray[i];
      //cout << "Current number: " << storedArray[i];    //Debug statement to make sure the loop is working
      storedArray[i] = storedArray[j];
      storedArray[j] = temp;
      j--;
  }
}


} // namespace ds

#endif // __ARRAY_H__

