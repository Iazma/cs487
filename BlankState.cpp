#include "BlankState.h"

#include "NodeVisitor.h"
#include "BoardNode.h"

BlankState::BlankState (void) {
}

BlankState::~BlankState (void) {
}

bool BlankState::isBlank (void) {
  return true;
}

void BlankState::printColor (std::ostream & out) {
  out << "Blank";
}

Hex::Color BlankState::getColor (void) {
  return Hex::BLANK;
}

void BlankState::accept (BoardNode * n, NodeVisitor & v) {
  v.visitBlank(n);
}
