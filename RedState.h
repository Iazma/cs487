#ifndef RED_STATE_H
#define RED_STATE_H

#include "NodeState.h"

#include <memory>

// Class representing the state of a red node
class RedState : public NodeState {
  public:
    // Constructor/destructor
    RedState (void);
    ~RedState (void);

    // Accept visitors
    void accept (NodeVisitor & v, BoardNode & n);
};

#endif
