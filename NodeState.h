#ifndef NODE_STATE_H
#define NODE_STATE_H

#include "Hex.h"
#include <memory>
#include <iostream>

class BoardNode;
class NodeVisitor;

// Abstract class representing state of a BoardNode
class NodeState {
  public:
    NodeState (void);
    virtual ~NodeState (void);

    // Report if color of state is blank
    virtual bool isBlank (void);

    // Print the node's color
    virtual void printColor (std::ostream & out) = 0;

    // Get the Hex::Color for the node
    virtual Hex::Color getColor (void) = 0;

    // Accept visitors to the state
    virtual void accept (BoardNode * n, NodeVisitor & v) = 0;
};
#endif
