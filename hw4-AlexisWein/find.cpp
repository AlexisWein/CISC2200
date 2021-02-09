#include "SortedList.h"

int findInsertPosition(ds::SortedList<int> &list, int target) {
  // TODO: Find the position to insert "target" in sorted list "l", or return
  //       the index if "target" is found in "l"
  // NOTE: You should implement the function using *binary search algorithm*.
  //       You may assume no duplicates in the list.
  //       Current position of list is 0 before the execution of the function
  //       and should be 0 after the execution.

  //Based on the pseudocode from Wikipedia linked in the instructions
  int curr = 0;
  int last = list.length() - 1;
  int m = (curr + last)/2;
  
  while(curr <= last)
  {
    m = (curr + last)/2;
    list.moveToPos(m);
    
    if(list.getValue() < target)
    {
      curr = m+1;
    }
    else if(list.getValue() > target)
    {
      last = m-1;
    }
    else
    {
      return m;
    }
    list.moveToStart();           //moves the cursor back to the beginning
  }
}
