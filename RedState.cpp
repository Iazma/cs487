#include "RedState.h"

#include "NodeVisitor.h"
#include "BoardNode.h"

RedState::RedState (void) {
};

RedState::~RedState (void) {
};

void RedState::printColor (std::ostream & out) {
  out << "Red";
}

Hex::Color RedState::getColor (void) {
  return Hex::RED;
}

void RedState::accept (BoardNode * n, NodeVisitor & v) {
  v.visitRed(n);
}
