#include "NodeStateFactory.h"

#include "NodeState.h"
#include "BlueState.h"
#include "RedState.h"
#include "BlankState.h"

NodeStateFactory::NodeStateFactory (void) 
  : blueInstance(std::make_shared<BlueState>())
    ,redInstance(std::make_shared<RedState>())
    ,blankInstance(std::make_shared<BlankState>())
{};

std::shared_ptr<NodeState> NodeStateFactory::getBlueState (void) {
  return blueInstance;
}

std::shared_ptr<NodeState> NodeStateFactory::getRedState (void) {
  return redInstance;
}

std::shared_ptr<NodeState> NodeStateFactory::getBlankState (void) {
  return blankInstance;
}
