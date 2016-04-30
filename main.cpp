#include "Manager.h"
#include "RandomPlayer.h"
#include "Hex.h"
#include "NodeStateFactory.h"

#include <iostream>

int main (void) {
  std::shared_ptr<RandomPlayer> p1 = std::make_shared<RandomPlayer>(NodeStateFactory::getFactory()->getBlueState());
  std::shared_ptr<RandomPlayer> p2 = std::make_shared<RandomPlayer>(NodeStateFactory::getFactory()->getRedState());

  Manager manager(10, p1, p2);

  manager.run();

  return 0;
}
