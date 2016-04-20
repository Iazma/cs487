#include "BoardState.h"

#include "BoardNode.h"

BoardState::BoardState (int size) 
  : size_(size)
{
  board.resize(size_);

  for (int y = 0; y < size_; ++y) {
    std::vector<std::shared_ptr<BoardNode>> * row = &board[y];

    for (int x = 0; x < size_; ++x) {
      auto node = std::make_shared<BoardNode>(x, y);

      if (y > 0) {
        node->setUL( board[y-1][x] );
        board[y-1][x]->setDR(node);

        if (x < size_-1) {
          node->setUR( board[y-1][x+1] );
          board[y-1][x+1]->setDL(node);
        }
      }

      if (x > 0) {
        node->setL( board[y][x-1] );
        board[y][x-1]->setR(node);
      }

      row->push_back(node);
    }
  }
}

std::shared_ptr<BoardNode> BoardState::get (int x, int y) const {
  return board[y][x];
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
