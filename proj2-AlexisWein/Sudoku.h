#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#include <iostream>

namespace ds {

class Sudoku {
private:
  int grid[9][9];

public:
  Sudoku() {}

  void readFrom1DArray(int *grid);
  void solve();
  bool recursiveSolve(int row, int col);
  bool isValid(int row, int col, int n);

  void print1D() const {
    for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
        if (row != 0 || col != 0)
          std::cout << " ";
        std::cout << grid[row][col];
      }
      //std::cout << "\n";                    //makes output more clear (for my use)
    }
  }
};

} // namespace ds

#endif // __SUDOKU_H__