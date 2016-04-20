#ifndef BOARD_STATE_H
#define BOARD_STATE_H

#include <memory>
#include <vector>

#include "Hex.h"

// Forward declarations
class BoardNode;
class HexMove;

// Class representing a Hex board
class BoardState {
  public:
    // Initialize a board of size n x n
    BoardState (int size);

    // Get the board node from the given x and y coordinates
    std::shared_ptr<BoardNode> get (int x, int y) const;

    // Get the begin() iterator for the given row
    std::vector<std::shared_ptr<BoardNode>>::iterator getRowIterator (int x);

    // Get the end() iterator for the given row
    std::vector<std::shared_ptr<BoardNode>>::iterator getRowEnd (int x);
    // Set a board node to a given color
    void set (int x, int y, Hex::Color color);

    // Get board size
    int getSize (void);

  private:
    // 2D vector of board pointers
    std::vector<std::vector<std::shared_ptr<BoardNode>>> board;

    // Board size
    int size_;
};

#endif
