#ifndef PLAYER_H
#define PLAYER_H

#include "Hex.h"
#include <memory>
#include <iostream>

// Forward declarations
class BoardState;
class HexMove;
class NodeState;

// Abstract class representing a Player of the game
class Player {
  public:
    // Initialize a Player to a specific color
    Player (std::shared_ptr<NodeState> c);

    virtual ~Player (void) {};

    // Color getter
    Hex::Color getColor (void);

    // Print player's color
    void printColor (std::ostream & out);

    // Take a turn
    virtual HexMove playTurn (BoardState & board) = 0;

    // Inform the player that they won
    virtual void win (void) = 0;

    // Inform the player that they lost
    virtual void lose (void) = 0;

  protected:
    std::shared_ptr<NodeState> color;
};

#endif
