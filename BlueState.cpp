#include "BlueState.h"

#include "NodeVisitor.h"

BlueState::BlueState (void) {
};

BlueState::~BlueState (void) {
};

void BlueState::printColor (std::ostream & out) {
  out << "Blue";
}

Hex::Color BlueState::getColor (void) {
  return Hex::BLUE;
}

void BlueState::accept (BoardNode * n, NodeVisitor & v) {
  v.visitBlue(n);
}
