#include <iostream>
#include <vector>
#include <set>
#include <random>

auto queen = "\u265B";
auto boardSize = 8;
auto validOptions = std::set<int>{0, 1, 2, 3, 4, 5, 6, 7};
std::random_device rd;
std::mt19937 randomGen(rd());


/*
  board indicates position of queen in a row
*/
using boardType = std::vector<int>;

/**
 * print out a board with queen character
 */ 
void printBoard(const boardType &board) {
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
bool doRecurse(boardType &board, int index, int &stepCounter) {
  stepCounter++;
  auto takenValues = std::set<int>{};

  for (int i = 0; i < index; i++) {
    auto diff = index - i;
    auto value = board.at(i);
    takenValues.insert(value);
    takenValues.insert(value + diff);
    takenValues.insert(value - diff);
  }

  std::vector<int> remainingOptions;
  std::set_difference(
    validOptions.begin(), validOptions.end(),
    takenValues.begin(), takenValues.end(),
    std::inserter(remainingOptions, remainingOptions.begin())
  );

  std::shuffle(remainingOptions.begin(), remainingOptions.end(), randomGen);

  for(auto option : remainingOptions) {
    board[index] = option;

    if (index == boardSize - 1 || doRecurse(board, index + 1, stepCounter)) {
      return true;
    }

    board[index] = -1;
  }

  return false;
}

/**
 * kick off recursive solver
 */
int recursiveSolver(boardType &board) {
  auto stepCounter = 0;
  doRecurse(board, 0, stepCounter);
  return stepCounter;
}

/**
 * ren
 */

int main () {
  std::cout << "Recursive Solver: " << '\n';
  auto board = createBoard();
  auto stepCounter = recursiveSolver(board);
  printBoard(board);
  std::cout << "Steps: " << stepCounter << '\n';
}