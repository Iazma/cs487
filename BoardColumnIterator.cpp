#include "BoardColumnIterator.h"

#include "BoardNode.h"

BoardColumnIterator::BoardColumnIterator (std::shared_ptr<BoardNode> start)
  : BoardStraightIterator(start)
{};

BoardColumnIterator & BoardColumnIterator::operator++ (void) {
  if (current) {
    current = current->getDR();
  }

  return *this;
}

void BoardColumnIterator::operator++ (int) {
  ++(*this);
}

BoardColumnIterator & BoardColumnIterator::operator-- (void) {
  if (current) {
    current = current->getUL();
  }

  return *this;
}

void BoardColumnIterator::operator-- (int) {
  --(*this);
}


