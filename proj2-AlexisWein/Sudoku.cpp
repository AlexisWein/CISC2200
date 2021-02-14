#include "Sudoku.h"

namespace ds {

/**
 * This function takes the input (a 1D array with 81 integers) and converts it to a
 * 2D array with 9 rows and 9 columns. This is my original code.
 * I left some old code and debugging statements commented out to show my work.
 **/
void Sudoku::readFrom1DArray(int *board) {
  // TODO: read the grid in the 1D array `board` to the 2D array
  // `this->grid`
  // NOTE: the `board` contains 81 `int`s, `this->grid` is 9x9
  
  //int temp[9][9];                       //old code
  int index = 0;
  for(int i=0; i < 9; i++)
  {
    for(int j=0; j<9; j++)
    {
      this->grid[i][j] = board[index];
      //std::cout << grid[i][j] << std::endl;             //debugging statement
      index++;
      //std::cout << "index: " << index << std::endl;     //debugging statement
    }
  }
}

/**
 * This function calls a helper function (recursiveSolve) to solve the sudoku board recursively
 * * This is my original code. I left some old code and debugging statements commented out to show my work.
 **/
void Sudoku::solve() {
  // TODO: solve the sudoku puzzle by setting 1-9 to cells in `grid`
  
  bool solved;
  solved = recursiveSolve(0, 0);
}
/**
 * For this function, I used a few internet sources for reference.
 * https://en.wikipedia.org/wiki/Sudoku_solving_algorithms was linked in the assignment instructions. I used it to help me understand the logic of backtracking.
 * http://web.eecs.utk.edu/~bvanderz/cs140/Notes/Sudoku/ this website also helped me understand the logic behind this lab. These are lecture notes from another university.
 * https://www.geeksforgeeks.org/sudoku-backtracking-7/ I based my function on the logic of the code on this website
 * At the end of this function is my first attempt at this function, before I used sources for help.
 * There are several bugs in that part of the code, as I explain in the comments.
**/
bool Sudoku::recursiveSolve(int row, int col) {
  
  if(col > 8  &&  row < 8)                  //you've reached the last column, but not the last row.
  {
    row++;                                  //increment row to move to the next row
    col = 0;                                //set column back to 0 to start at the beginning of the next row
  }

  if(col > 8)                               //you've reached the last row and the last column, which means the puzzle has been solved successfully; return true
    return true;

  if(this->grid[row][col] != 0)             //this means the slot is not empty; skip this and move on to the next slot
    return(recursiveSolve(row, col+1));

  for(int i = 1; i <= 9; i++)               //this for loop tests different numbers 1-9 for empty slots in the grid
  {
    if(isValid(row, col, i))                //checks if the number is a valid input for the slot
    {
      this->grid[row][col] = i;             //sets the number in the current slot to i if i is valid
      
      if(recursiveSolve(row, col+1))        //recursively goes through the rest of the grid; if you reach the end and it is true, return true; the puzzle is solved
        return true;
    }
    this->grid[row][col] = 0;               //if i is not valid, make the number in the slot = 0 again
  }
  return false;
  
}

/**
 * This helper function checks if the number you are trying to insert in the sudoku board is a valid answer
 * for that spot. It checks if the number already exists in the row, column, or 3x3 grid.
 * This is my original code. I left some old code and debugging statements commented out to show my work.
 **/
bool Sudoku::isValid(int row, int col, int num){
  bool rowBool = true;
  bool colBool = true;
  bool boxBool = true;
  for(int i = 0; i < 9; i++)        //checks if the number already exists in the row
  {
    //std::cout << "row test" << std::endl;           //debugging statement
    if(this->grid[row][i] == num)
      rowBool = false;
  }

  for(int i = 0; i < 9; i++)        //checks if the number already exists in the column
  {
    //std::cout << "col test" << std::endl;           //debugging statement
    if(this->grid[i][col] == num)
      colBool = false;
  }

  for(int i = row - (row % 3); i < row - (row%3) + 3; i++)        //checks if the number already exists in its box
  {
    //std::cout << "box outer test" << std::endl;     //debugging statement
    for(int j = col - (col % 3); j < col - (col%3) + 3; j++)
    {
      //std::cout << "box inner test" << std::endl;   //debugging statement
      if(this->grid[i][j] == num)
        boxBool = false;
    }
  }

  if(rowBool == true  &&  colBool == true  &&  boxBool == true)      //if all 3 statements are true, the number is valid
  {
    //std::cout << "final if test" << std::endl;      //debugging statement
    return true;
  }

  return false;
}

} // namespace ds
