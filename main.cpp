#include <iostream>
#include <vector>

auto queen = "\u265B";

/*
  board
    add piece at
    remove piece at
    move piece
    print board
*/
using boardType = std::vector<uint>;

void printBoard(boardType board) {

}

/* 
  recursive solver
    1 start with first row 
    2 identify available spots
    3 if no spots available, return false
    4 select spot
    5 if last queen, return true
    6 if not, remove spot return false (go to two)
    7 return result of recursion on next row 
*/


int main () {
  auto board = boardType{0, 0, 0, 0, 0, 0, 0, 0};

  for (auto i = 0; i < board.size(); i++) {
    board[i] = i;
  }
  
  for (auto i = 0; i < board.size(); i++) {
    std::cout << queen  << ' ';
  }
  std::cout << '\n';
}