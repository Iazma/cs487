#include "NodeStateFactory.h"

#include "NodeState.h"
#include "BlueState.h"
#include "RedState.h"
#include "BlankState.h"
#include "DummyState.h"

NodeStateFactory::NodeStateFactory (void) 
  : blueInstance(std::make_shared<BlueState>())
    ,redInstance(std::make_shared<RedState>())
    ,blankInstance(std::make_shared<BlankState>())
    ,dummyBlueInstance(std::make_shared<DummyBlue>())
    ,dummyRedInstance(std::make_shared<DummyRed>())
    ,dummyPurpleInstance(std::make_shared<DummyPurple>())
{};

std::shared_ptr<NodeStateFactory> NodeStateFactory::getFactory (void) {
  if (!factoryInstance) {
    factoryInstance = std::make_shared<NodeStateFactory>();
  }

  return factoryInstance;
}

std::shared_ptr<NodeState> NodeStateFactory::getBlueState (void) {
  return blueInstance;
}

std::shared_ptr<NodeState> NodeStateFactory::getRedState (void) {
  return redInstance;
}

std::shared_ptr<NodeState> NodeStateFactory::getBlankState (void) {
  return blankInstance;
}

std::shared_ptr<NodeState> NodeStateFactory::getBlueDummyState (void) {
  return dummyBlueInstance;
}

std::shared_ptr<NodeState> NodeStateFactory::getRedDummyState (void) {
  return dummyRedInstance;
}

std::shared_ptr<NodeState> NodeStateFactory::getPurpleDummyState (void) {
  return dummyPurpleInstance;
}
