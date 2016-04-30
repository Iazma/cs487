#include "RandomPlayer.h"

#include <cstdlib>
#include <time.h>
#include <iostream>
#include "BoardNode.h"
#include "BoardState.h"
#include "HexMove.h"

RandomPlayer::RandomPlayer (std::shared_ptr<NodeState> c)
  : Player(c)
{};

HexMove RandomPlayer::playTurn (BoardState & board) {
  std::shared_ptr<BoardNode> node;

  // Get some random numbers
  srand(time(NULL));
  int size = board.getSize();
  unsigned int x = rand() % size;
  unsigned int y = rand() % size;

  // Initial randomly selected node
  node = board.get(x, y);

  // Until you find a blank node, keep randomly searching
  while (!node->isBlank()) {
    x = (x + rand()) % size;
    y = (y + rand()) % size;

    node = board.get(x, y);
  }

  return node->getLocation();
}

void RandomPlayer::win (void) {
  this->printColor(std::cout);
  std::cout << " WINS YAY ME!" << std::endl;
}

void RandomPlayer::lose (void) {
  // you probably cheated!
}
