#include "RedWinSearcher.h"

#include "BoardNode.h"
#include "BoardState.h"
#include "BoardRowIterator.h"
#include "RedNeighborVisitor.h"

RedWinSearcher::RedWinSearcher (BoardState & b)
  : WinSearcher(b)
{
  fringeAddVisitor = std::make_shared<RedNeighborVisitor>(this->fringe);
}

void RedWinSearcher::setup (void) {
  BoardRowIterator top (board.get(0,0));
  BoardRowIterator bottom (board.get(0, board.getSize()));

  // Clear stuff
  fringe.clear();
  visited.clear();
  goalList.clear();

  // First get goal nodes
  while (!bottom.finished()) {
    bottom->accept(*fringeAddVisitor);
    ++bottom;
  }

  // Put them in goal map
  for (auto it = fringe.begin(); it != fringe.end(); ++it) {
    goalList[*it] = true;
  }
  fringe.clear();

  // Now get the start nodes
  while (!top.finished()) {
    top->accept(*fringeAddVisitor);
    ++top;
  }
}
