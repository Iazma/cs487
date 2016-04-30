#ifndef BOARD_NODE_H
#define BOARD_NODE_H

#include <map>
#include <memory>
#include <string>

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
    
    BoardNode (BoardNode & copy);

    virtual ~BoardNode (void);

    // Get the coordinates of this node
    HexMove getLocation (void) const;

    // Set color of hex
    void colorize (Hex::Color color);

    // Returns true if node is blank
    bool isBlank (void);

    // Neighbor getters
    std::shared_ptr<BoardNode> getUL (void);
    std::shared_ptr<BoardNode> getUR (void);
    std::shared_ptr<BoardNode> getL (void) ;
    std::shared_ptr<BoardNode> getR (void);
    std::shared_ptr<BoardNode> getDL (void);
    std::shared_ptr<BoardNode> getDR (void);

    std::map<std::string, std::shared_ptr<BoardNode>> & getNeighbors (void);

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
    std::map<std::string, std::shared_ptr<BoardNode>> neighbors;

    // Location information
    int x_;
    int y_;

    // Color state
    std::shared_ptr<NodeState> state;
};

#endif
