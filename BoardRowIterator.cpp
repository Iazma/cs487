#include "BoardRowIterator.h"

#include "BoardNode.h"

BoardRowIterator::BoardRowIterator (std::shared_ptr<BoardNode> start)
  : BoardStraightIterator(start)
{};

BoardRowIterator & BoardRowIterator::operator++ (void) {
  if (current) {
    this->current = this->current->getR();
  }
  return *this;
}

void BoardRowIterator::operator++ (int) {
  ++(*this);
}

BoardRowIterator & BoardRowIterator::operator-- (void) {
  if (current) {
    this->current = this->current->getL();
  }

  return *this;
}

void BoardRowIterator::operator-- (int) {
  --(*this);
}
