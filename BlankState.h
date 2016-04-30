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

    // Returns true for this state
    bool isBlank (void);

    void printColor (std::ostream & out);

    Hex::Color getColor (void);

    // Accept visitors
    void accept (BoardNode * n, NodeVisitor & v);
};

#endif
