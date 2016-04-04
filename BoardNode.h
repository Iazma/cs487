#ifndef BOARD_NODE_H
#define BOARD_NODE_H

#include <memory>

#include "Hex.h"

// Forward declarations
class HexMove;

/// Class representing a space on the board
class BoardNode {
  public:
    // Init boardnode with it's place reference
    BoardNode (int x, int y);
    
    // Get the coordinates of this node
    HexMove getLocation (void) const;

    // Set color of hex
    void colorize (Hex::Color color);

    // Get color of hex
    Hex::Color getColor (void);

    // Neighbor getters
    BoardNode & getUL (void) const;
    BoardNode & getUR (void) const;
    BoardNode & getL (void) const;
    BoardNode & getR (void) const;
    BoardNode & getDL (void) const;
    BoardNode & getDR (void) const;

    // Neighbor setters
    void setUL (std::shared_ptr<BoardNode> node);
    void setUR (std::shared_ptr<BoardNode> node);
    void setL (std::shared_ptr<BoardNode> node);
    void setR (std::shared_ptr<BoardNode> node);
    void setDL (std::shared_ptr<BoardNode> node);
    void setDR (std::shared_ptr<BoardNode> node);

  private:
    // Neighbor pointers
    std::shared_ptr<BoardNode> upLeft;
    std::shared_ptr<BoardNode> upRight;
    std::shared_ptr<BoardNode> left;
    std::shared_ptr<BoardNode> right;
    std::shared_ptr<BoardNode> downLeft;
    std::shared_ptr<BoardNode> downRight;
};

#endif
