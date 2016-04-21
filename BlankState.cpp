#include "BlankState.h"

#include "NodeVisitor.h"
#include "BoardNode.h"

BlankState::BlankState (void) {
}

BlankState::~BlankState (void) {
}

void BlankState::accept (BoardNode & n, NodeVisitor & v) {
  v.visitBlank(n);
}
