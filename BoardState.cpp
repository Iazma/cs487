#include "BoardState.h"

#include "BoardNode.h"

BoardState::BoardState (int size) 
  : size_(size)
{
  board.resize(size_);

  for (int x = 0; x < size_; ++x) {
    std::vector<std::shared_ptr<BoardNode>> * row = &board[x];

    for (int y = 0; y < size_; ++y) {
      row->push_back(std::make_shared<BoardNode>(x, y));
    }
  }
}

std::shared_ptr<BoardNode> BoardState::get (int x, int y) const {
  return board[x][y];
}

std::vector<std::shared_ptr<BoardNode>>::iterator BoardState::getRowIterator (int x) {
  return board[x].begin();
}

std::vector<std::shared_ptr<BoardNode>>::iterator BoardState::getRowEnd (int x) {
  return board[x].end();
}

void BoardState::set (int x, int y, Hex::Color color) {
  board[x][y]->colorize(color);
}

int BoardState::getSize (void) {
  return size_;
}
