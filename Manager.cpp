#include "Manager.h"

#include <iostream>
#include "HexMove.h"
#include "Player.h"
#include "BlueWinSearcher.h"
#include "RedWinSearcher.h"
#include "BoardPrinter.h"

Manager::Manager (int size, std::shared_ptr<Player> p1, std::shared_ptr<Player> p2)
  : player1(p1)
  ,player2(p2)
    ,board(size)
{};

void Manager::run (void) {
  BlueWinSearcher blueSearch(board);
  RedWinSearcher redSearch(board);

  while(1) {
    std::cout << "Player 1 turn" << std::endl;
    doPlayerMove(*player1);
    if (blueSearch.findPath()) {
      player1->win();
      player2->lose();
      return;
    }

    std::cout << "Player 2 turn" << std::endl;
    doPlayerMove(*player2);
    if (redSearch.findPath()) {
      player1->lose();
      player2->win();
      return;
    }
    BoardPrinter::printBoard(board);
  }
}

void Manager::doPlayerMove (Player & p) {
  HexMove move = p.playTurn(board);

  std::cout << "Have move " << move.getX() << " " << move.getY() << ", setting..." << std::flush; 
  board.set(move.getX(), move.getY(), p.getColor());
  std::cout << " set." << std::endl;
}
