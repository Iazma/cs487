#include "BlueState.h"

#include "NodeVisitor.h"

BlueState::BlueState (void) {
};

BlueState::~BlueState (void) {
};

void BlueState::accept (NodeVisitor & v, BoardNode & n) {
  v.visitBlue(n);
}
