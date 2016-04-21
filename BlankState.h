#ifndef BLANK_STATE_H
#define BLANK_STATE_H

#include "NodeState.h"

#include <memory>

// Class representing the state of a blank node
class BlankState : public NodeState {
  public:
    // Constructor/destructor
    BlankState (void);
    ~BlankState (void);

    // Accept visitors
    void accept (NodeVisitor & v, BoardNode & n);
};

#endif
