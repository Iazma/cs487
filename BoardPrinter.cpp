#include "BoardPrinter.h"

#include "BoardState.h"
#include "BoardNode.h"
#include "Hex.h"
#include <iostream>

void BoardPrinter::printBoard (BoardState & board) {
  for (int rowNum = 0; rowNum < board.getSize(); ++rowNum) {
    auto it = board.getRowIterator(rowNum);
    auto end = board.getRowEnd(rowNum);

    if (rowNum % 2) std::cout << " ";

    while (it != end) {
      if ((*it)->getColor() == Hex::BLANK) {
        std::cout << "  ";
      }
      else if ((*it)->getColor() == Hex::BLUE) {
        std::cout << "B ";
      }
      else {
        std::cout << "R ";
      }
    }
    std::cout << std::endl;
  }
}
