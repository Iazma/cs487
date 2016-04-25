#include "RedNeighborVisitor.h"

#include "BoardNode.h"

RedNeighborVisitor::RedNeighborVisitor (std::deque<std::shared_ptr<BoardNode>> & f)
  : NeighborVisitor(f)
{};

RedNeighborVisitor::~RedNeighborVisitor (void) { };

void RedNeighborVisitor::visitBlue (BoardNode &) { /* no op */ };

void RedNeighborVisitor::visitRed (BoardNode & node) {
  fringe.emplace_back (node);
}

void RedNeighborVisitor::visitBlank (BoardNode &) { /* no op */ };

