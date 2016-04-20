#include "RandomPlayer.h"

#include <cstdlib>
#include <time.h>
#include <iostream>
#include "BoardNode.h"
#include "BoardState.h"
#include "HexMove.h"

RandomPlayer::RandomPlayer (Hex::Color color)
  : Player(color)
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
  while (node->getColor() != Hex::BLANK) {
    x = (x + rand()) % size;
    y = (y + rand()) % size;

    node = board.get(x, y);
  }

  return node->getLocation();
}

void RandomPlayer::win (void) {
  std::cout << this->playerColor << " WINS YAY ME!" << std::endl;
}

void RandomPlayer::lose (void) {
  // you probably cheated!
}
