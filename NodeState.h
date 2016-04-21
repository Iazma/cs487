#ifndef NODE_STATE_H
#define NODE_STATE_H

#include "Hex.h"

class BoardNode;
class NodeVisitor;

// Abstract class representing state of a BoardNode
class NodeState {
  public:
    virtual ~NodeState (void);

    // Accept visitors to the state
    virtual void accept (BoardNode & n, NodeVisitor & v) = 0;
};
#endif
