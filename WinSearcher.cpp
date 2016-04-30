#include "WinSearcher.h"

#include "BoardState.h"
#include "BoardNode.h"
#include "NeighborVisitor.h"
#include "BoardStraightIterator.h"

WinSearcher::WinSearcher (BoardState & b)
  : board(b)
{};

bool WinSearcher::findPath (void) {
  setup();

  // If the goalList map is empty there cannot be a victory condition
  if (goalList.size() == 0) {
    return false;
  }

  while (!fringe.empty()) {
    std::shared_ptr<BoardNode> node = fringe.back();
    if (goalList.count(node)) {
      return true;
    }

    visitNeighbors(node);
    fringe.pop_back();
  }

  return false;
}

void WinSearcher::visitNeighbors (std::shared_ptr<BoardNode> node) {
  for (auto neighbor : node->getNeighbors() ) {
    neighbor.second->accept(*fringeAddVisitor);
  }
}
