#include "Player.h"

Player::Player (Hex::Color color) 
  : playerColor(color) {};

Hex::Color Player::getColor (void) {
  return playerColor;
}

void Player::swapColor (void) {
  if (playerColor == Hex::BLUE) {
    playerColor = Hex::RED;
  }
  else {
    playerColor = Hex::BLUE;
  }
}
