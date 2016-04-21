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

    // Accept visitors
    void accept (NodeVisitor & v, BoardNode & n);
};
#endif
