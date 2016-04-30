#include "BlueNeighborVisitor.h"

#include "BoardNode.h"

#include <deque>

BlueNeighborVisitor::BlueNeighborVisitor (std::deque<std::shared_ptr<BoardNode>> & f)
  : NeighborVisitor(f)
{};

BlueNeighborVisitor::~BlueNeighborVisitor (void) { };

void BlueNeighborVisitor::visitBlue (BoardNode * node) {
  this->fringe.emplace_back(node);
}
