#include "NodeStateFactory.h"

#include "NodeState.h"
#include "BlueState.h"
#include "RedState.h"
#include "BlankState.h"
#include "DummyState.h"

// Initialize static variable
NodeStateFactory * NodeStateFactory::factoryInstance = nullptr;

NodeStateFactory::NodeStateFactory (void) 
  : blueInstance(std::make_shared<BlueState>())
    ,redInstance(std::make_shared<RedState>())
    ,blankInstance(std::make_shared<BlankState>())
{};

void NodeStateFactory::killFactory (void) {
  delete factoryInstance;
}

NodeStateFactory * NodeStateFactory::getFactory (void) {
  if (!factoryInstance) {
    factoryInstance = new NodeStateFactory();
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
  return nullptr;
}

std::shared_ptr<NodeState> NodeStateFactory::getRedDummyState (void) {
  return nullptr;
}

std::shared_ptr<NodeState> NodeStateFactory::getPurpleDummyState (void) {
  return nullptr;
}
