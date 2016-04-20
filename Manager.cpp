#include "Manager.h"

#include <iostream>
#include "HexMove.h"
#include "Player.h"
#include "WinSearcher.h"
#include "BoardPrinter.h"

Manager::Manager (int size, std::shared_ptr<Player> p1, std::shared_ptr<Player> p2)
  : player1(p1)
  ,player2(p2)
    ,board(size)
{};

void Manager::run (void) {
  while(1) {
    std::cout << "Player 1 turn" << std::endl;
    if (doPlayerMove(*player1)) {
      player1->win();
      player2->lose();
      return;
    }

    std::cout << "Player 2 turn" << std::endl;
    if (doPlayerMove(*player2)) {
      player1->lose();
      player2->win();
      return;
    }
    BoardPrinter::printBoard(board);
  }
}

bool Manager::doPlayerMove (Player & p) {
  HexMove move = p.playTurn(board);

  std::cout << "Have move " << move.getX() << " " << move.getY() << ", setting..." << std::flush; 
  board.set(move.getX(), move.getY(), p.getColor());
  std::cout << " set." << std::endl;

  return boardCheck();
}

bool Manager::boardCheck (void) {
  WinSearcher blueSearch(Hex::BLUE, board);
  WinSearcher redSearch(Hex::RED, board);

  if (blueSearch.findPath() || redSearch.findPath()) {
    return true;
  }
  return false;
}
