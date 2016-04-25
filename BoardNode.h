#ifndef BOARD_NODE_H
#define BOARD_NODE_H

#include <memory>

#include "Hex.h"

// Forward declarations
class HexMove;
class NodeState;
class BoardNodeIterator;
class NodeVisitor;
class NodeStateFactory;

/// Class representing a space on the board
class BoardNode {
  public:
    // Init boardnode with it's place reference
    BoardNode (int x, int y);
    
    virtual ~BoardNode (void);

    // Get the coordinates of this node
    HexMove getLocation (void) const;

    // Set color of hex
    void colorize (Hex::Color color);

    // Neighbor getters
    std::shared_ptr<BoardNode> getUL (void) const;
    std::shared_ptr<BoardNode> getUR (void) const;
    std::shared_ptr<BoardNode> getL (void) const;
    std::shared_ptr<BoardNode> getR (void) const;
    std::shared_ptr<BoardNode> getDL (void) const;
    std::shared_ptr<BoardNode> getDR (void) const;

    // Neighbor setters
    void setUL (std::shared_ptr<BoardNode> node);
    void setUR (std::shared_ptr<BoardNode> node);
    void setL (std::shared_ptr<BoardNode> node);
    void setR (std::shared_ptr<BoardNode> node);
    void setDL (std::shared_ptr<BoardNode> node);
    void setDR (std::shared_ptr<BoardNode> node);

    // Accept NodeVisitors
    virtual void accept (NodeVisitor & v);

  protected:
    // Neighbor pointers
    std::shared_ptr<BoardNode> upLeft;
    std::shared_ptr<BoardNode> upRight;
    std::shared_ptr<BoardNode> left;
    std::shared_ptr<BoardNode> right;
    std::shared_ptr<BoardNode> downLeft;
    std::shared_ptr<BoardNode> downRight;

    // Location information
    int x_;
    int y_;

    // Color state
    std::shared_ptr<NodeState> state;
};

#endif
