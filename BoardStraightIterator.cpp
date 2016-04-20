#include "BoardStraightIterator.h"

#include "BoardNode.h"

BoardStraightIterator::BoardStraightIterator (std::shared_ptr<BoardNode> start)
  : current(start)
{};

bool BoardStraightIterator::finished (void) {
  // Returns true if current == nullptr
  if (current) {
    return false;
  }
  return true;
}

BoardNode & BoardStraightIterator::operator* (void) {
  return *current;
}

BoardNode * BoardStraightIterator::operator-> (void) {
  return current.get();
}

bool operator== (const BoardStraightIterator & lhs, const BoardStraightIterator & rhs) {
  return (lhs.current == rhs.current);
}

bool operator!= (const BoardStraightIterator & lhs, const BoardStraightIterator & rhs) {
  return !(lhs == rhs);
}

const BoardStraightIterator & BoardStraightIterator::operator= (const BoardStraightIterator & rhs) {
  this->current = rhs.current;
  return *this;
}

