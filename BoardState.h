#ifndef BOARD_STATE_H
#define BOARD_STATE_H

#include <memory>
#include <vector>

#include "Hex.h"

// Forward declarations
class BoardNode;

// Class representing a Hex board
class BoardState {
  public:
    // Initialize a board of size n x n
    BoardState (int size);

    // Get the board node from the given x and y coordinates
    BoardNode & get (int x, int y) const;

    // Set a board node to a given color
    void set (int x, int y, Hex::Color color);

  private:
    // 2D vector of board pointers
    std::vector<std::vector<std::unique_ptr<BoardNode>>> board;
};

#endif
