#include "RedState.h"

#include "NodeVisitor.h"
#include "BoardNode.h"

RedState::RedState (void) {
};

RedState::~RedState (void) {
};

void RedState::accept (BoardNode & n, NodeVisitor & v) {
  v.visitRed(n);
}
