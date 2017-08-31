#include <iostream>
#include <vector>
#include <algorithm>

auto queen = "\u265B";
auto boardSize = 8;

/*
  board
    add piece at
    remove piece at
    move piece
    print board
*/
using boardType = std::vector<int>;

void printBoard(boardType board) {
  auto line = "+---+---+---+---+---+---+---+---+";

  for (auto rowPosition: board) {
    std::cout << '\n' << line << '\n';

    for(auto i = 0; i < boardSize; i++) {
      std::cout << "| ";

      if(i == rowPosition) {
        std::cout << queen << ' ';
      } else {
        std::cout << "  ";
      }
    }
    std::cout << '|';
  }
  
  std::cout << '\n' << line << '\n';
}

boardType createBoard() {
  return boardType{ -1, -1, -1, -1, -1, -1, -1, -1 };
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
void recursiveSolver() {
  auto board = createBoard();
  doRecurse(&board, 0);
  printBoard(board);
}

bool doRecurse(boardType &board, int index) {

}


int main () {
  recursiveSolver();

  char a;
  std::cin >> a;
}