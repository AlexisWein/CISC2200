#include "Array.h"
#include <iostream>

using std::cin;
using std::cout;

int main(int argc, char **argv) {
  // read integers into an Array object
  // 1st input: size of array
  // 2nd and so on: integer values
  int size;
  cin >> size;

  ds::Array<int> nums(size);
  for (int i = 0; i < size; i++) {
    cin >> nums[i];
  }

  nums.reverse();

  // print the array nums
  for (int i = 0; i < nums.length; i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << nums[i];
  }

  return 0;
}
