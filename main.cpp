#include "Manager.h"
#include "RandomPlayer.h"
#include "Hex.h"

#include <iostream>

int main (void) {
  std::shared_ptr<RandomPlayer> p1 = std::make_shared<RandomPlayer>(Hex::BLUE);
  std::shared_ptr<RandomPlayer> p2 = std::make_shared<RandomPlayer>(Hex::RED);

  Manager manager(10, p1, p2);

  manager.run();

  return 0;
}
