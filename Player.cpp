#include "Player.h"
#include "NodeState.h"

Player::Player (std::shared_ptr<NodeState> c) 
  : color(c) {};

Hex::Color Player::getColor (void) {
  return color->getColor();
}

void Player::printColor (std::ostream & out) {
  color->printColor(out);
}
