#include "WinSearcher.h"

#include "BoardState.h"
#include "BoardNode.h"

WinSearcher::WinSearcher (Hex::Color color, BoardState & board)
  : color_(color)
    ,board_(board)
{};

bool WinSearcher::findPath (void) {
  if (color_ == Hex::BLUE) {
    setupRows();
  }
  else {
    setupCols();
  }

  while (!fringe.empty()) {
    auto node = fringe.front();

    if (checkNeighbors(node)) {
      return true;
    }

    fringe.pop();
  }

  return false;
}

void WinSearcher::setupRows (void) {
  for (int i = 0; i < board_.getSize(); ++i) {
    auto node = board_.get(i, 0);
    auto goalNode = board_.get(i, board_.getSize()-1);

    if (node->getColor() == color_) {
      fringe.push(node);
    }
    visitedList[node] = true;

    if (goalNode->getColor() == color_) {
      goalList[board_.get(i, board_.getSize()-1)] = true;
    }
  }
}

void WinSearcher::setupCols (void) {
  for (int i = 0; i < board_.getSize(); ++i) {
    auto node = board_.get(0, i);

    fringe.push(node);
    visitedList[node] = true;

    goalList[board_.get(board_.getSize()-1, i)] = true;
  }
}

bool WinSearcher::checkNeighbors (std::shared_ptr<BoardNode> node) {
  auto check = [this](std::shared_ptr<BoardNode> neighbor) -> bool {
    if (neighbor == nullptr) return false;

    if (goalList.count(neighbor)) {
      return true;
    }

    if (visitedList.count(neighbor) == 0)  {
      fringe.push(neighbor);
      visitedList[neighbor] = true;
    }
    return false;
  };

  if ( check(node->getUL()) ) return true;
  if ( check(node->getUR()) ) return true;
  if ( check(node->getDL()) ) return true;
  if ( check(node->getDR()) ) return true;
  if ( check(node->getL()) ) return true;
  if ( check(node->getR()) ) return true;

  return false;
}



