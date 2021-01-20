#include "Array.h"
#include <iostream>
//using std::cout;  //used for debugging

ds::Array<int> runningSum(ds::Array<int> &nums) {
  // TODO: compute the running sum of the array
  
  int rSum = 0;
  for(int i = 0; i < nums.length; i++)
  {
    rSum += nums[i];
    //cout << "rSum: " << rSum << " ";    //used for debugging
    nums[i] = rSum;
    //cout << nums[i] << " ";   //used for debugging
  }
  //cout << "Hello.";  //used for debugging
  return nums;
}

int main(int argc, char **argv) {
  // read integers into an Array object
  // 1st input: size of array
  // 2nd and so on: integer values
  int size;
  std::cin >> size;

  ds::Array<int> nums(size);
  for (int i = 0; i < size; i++) {
    std::cin >> nums[i];
  }

  nums.reverse();
  ds::Array<int> result = runningSum(nums);
  //std::cout << "Test " << result[0] << result[1] << result[2] << std::endl;   //used for debugging

  // print running sum
  for (int i = 0; i < result.length; i++) {
    if (i != 0) {
      std::cout << " ";
    }
    std::cout << result[i];
  }

  return 0;
}
