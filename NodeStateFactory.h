#ifndef NODE_STATE_FACTORY_H
#define NODE_STATE_FACTORY_H

#include <memory>

class NodeState;
class BlueState;
class RedState;
class BlankState;

// Factory to get NodeStates from using the Flyweight pattern
class NodeStateFactory {
  public:
    // Constructor - Generate states
    NodeStateFactory (void);

    /* State getters */

    // Get a blue state
    std::shared_ptr<NodeState> getBlueState (void);

    // Get a red state
    std::shared_ptr<NodeState> getRedState (void);

    // Get a blank state
    std::shared_ptr<NodeState> getBlankState (void);

  private:
    // State instances 
    std::shared_ptr<BlueState> blueInstance;
    std::shared_ptr<RedState> redInstance;
    std::shared_ptr<BlankState> blankInstance;
};
#endif
