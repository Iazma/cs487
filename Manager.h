#ifndef MANAGER_H
#define MANAGER_H

#include <memory>

#include "BoardState.h"

// Forward declarations
class Player;

// Class to manage a game of Hex
class Manager {
  public:
    // Initialize manager with board game size and pointers to the player objects
    Manager (int size, std::shared_ptr<Player> p1, std::shared_ptr<Player> p2);

    // Begin running the game
    void run (void);

    // Ask for a player's move and process it
    // Returns true if that player won
    void doPlayerMove (Player & p);

  private:
    // Player pointers
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;

    // Current game's board
    BoardState board;
};

#endif
