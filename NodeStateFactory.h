#ifndef NODE_STATE_FACTORY_H
#define NODE_STATE_FACTORY_H

#include <memory>

class NodeState;
class BlueState;
class RedState;
class BlankState;
class DummyBlue;
class DummyRed;
class DummyPurple;

// Factory to get NodeStates from using the Flyweight pattern
class NodeStateFactory {
  public:
    // Singleton up in this place
    static std::shared_ptr<NodeStateFactory> getFactory (void);
    /* State getters */

    // Get a blue state
    std::shared_ptr<NodeState> getBlueState (void);

    // Get a red state
    std::shared_ptr<NodeState> getRedState (void);

    // Get a blank state
    std::shared_ptr<NodeState> getBlankState (void);

    // Get a blue dummy
    std::shared_ptr<NodeState> getBlueDummyState (void);

    // Get a red dummy
    std::shared_ptr<NodeState> getRedDummyState (void);

    // Get a purple dummy
    std::shared_ptr<NodeState> getPurpleDummyState (void);
  private:
    NodeStateFactory (void);

    static std::shared_ptr<NodeStateFactory> factoryInstance;

    // State instances 
    std::shared_ptr<BlueState> blueInstance;
    std::shared_ptr<RedState> redInstance;
    std::shared_ptr<BlankState> blankInstance;
    std::shared_ptr<DummyBlue> dummyBlueInstance;
    std::shared_ptr<DummyRed> dummyRedInstance;
    std::shared_ptr<DummyPurple> dummyPurpleInstance;
};
#endif
