#include "BoardCrossIterator.h"

#include "BoardNode.h"

BoardCrossIterator::BoardCrossIterator (std::shared_ptr<BoardNode> start)
  : BoardStraightIterator(start)
{}

BoardCrossIterator::~BoardCrossIterator (void) { }

BoardCrossIterator & BoardCrossIterator::operator++ (void) {
  if (this->current) {
  this->current = this->current->getUR();
  }

  return *this;
}

void BoardCrossIterator::operator++ (int) {
  ++(*this);
}

BoardCrossIterator & BoardCrossIterator::operator-- (void) {
  if (this->current) {
    this->current = this->current->getDL();
  }

  return *this;
}

void BoardCrossIterator::operator-- (int) {
  --(*this);
}
