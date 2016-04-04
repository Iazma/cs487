#ifndef BOARD_STATE_H
#define BOARD_STATE_H

#include <memory>
#include <vector>

class BoardNode;

namespace Hex {
  enum Color { BLUE, RED };
}

class BoardState {
  public:
    // Initialize a board of size n x n
    BoardState (int size);

    // Get the board node from the given x and y coordinates
    BoardNode & get (int x, int y) const;

    // Set a board node to a given color
    void set (int x, int y, Hex::Color color);

  private:
    std::vector<std::vector<std::unique_ptr<BoardNode>>> board;
};

#endif
