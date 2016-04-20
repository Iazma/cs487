#include "BoardColumnIterator.h"

#include "BoardNode.h"

BoardColumnIterator::BoardColumnIterator (std::shared_ptr<BoardNode> start)
  : current(start)
{};

bool BoardColumnIterator::finished (void) {
  // Returns true if current == nullptr
  if (current) {
    return false;
  }
  return true;
}

BoardColumnIterator & BoardColumnIterator::operator++ (void) {
  if (current) {
    current = current->getDR();
  }

  return *this;
}

BoardColumnIterator BoardColumnIterator::operator++ (int) {
  BoardColumnIterator temp = *this;

  ++(*this);

  return temp;
}

BoardColumnIterator & BoardColumnIterator::operator-- (void) {
  if (current) {
    current = current->getUL();
  }

  return *this;
}

BoardColumnIterator BoardColumnIterator::operator-- (int) {
  BoardColumnIterator temp = *this;

  --(*this);

  return temp;
}

BoardNode & BoardColumnIterator::operator* (void) {
  return *current;
}

BoardNode * BoardColumnIterator::operator-> (void) {
  return current.get();
}

bool operator== (const BoardColumnIterator & lhs, const BoardColumnIterator & rhs) {
  return (lhs.current == rhs.current);
}

bool operator!= (const BoardColumnIterator & lhs, const BoardColumnIterator & rhs) {
  return !(lhs == rhs);
}

const BoardColumnIterator & BoardColumnIterator::operator= (const BoardColumnIterator & rhs) {
  this->current = rhs.current;
  return *this;
}

