#ifndef BLUE_STATE_H
#define BLUE_STATE_H

#include "NodeState.h"

#include <memory>

// Class representing the state of a blue node
class BlueState : public NodeState {
  public:
    // Constructor/deconstructor
    BlueState (void);
    ~BlueState (void);

    void printColor (std::ostream & out);

    Hex::Color getColor (void);

    // Accept visitors
    void accept (BoardNode * n, NodeVisitor & v);
};
#endif
