#include "NeighborVisitor.h"

NeighborVisitor::NeighborVisitor (std::deque<std::shared_ptr<BoardNode>> & f)
  : fringe(f)
{};

NeighborVisitor::~NeighborVisitor (void) {}
