#include "BlueWinSearcher.h"

#include "BoardState.h"
#include "BlueNeighborVisitor.h"
#include "BoardColumnIterator.h"
#include "BoardNode.h"

BlueWinSearcher::BlueWinSearcher (BoardState & b) 
  : WinSearcher(b)
{
  fringeAddVisitor = std::make_shared<BlueNeighborVisitor>(this->fringe);
};

void BlueWinSearcher::setup (void) {
  BoardColumnIterator left (board.get(0,0));
  BoardColumnIterator right (board.get(board.getSize(), 0));

  // Clear stuff
  fringe.clear();
  visited.clear();
  goalList.clear();

  // First get the goal nodes
  while (!right.finished()) {
    right->accept(*fringeAddVisitor);
  }

  // And put them in the goal map
  for (auto it = fringe.begin(); it != fringe.end(); ++it) {
    goalList[*it] = true;
  }
  fringe.clear();

  // Now get the start nodes
  while (!left.finished()) {
    left->accept(*fringeAddVisitor);
  }
}

