#ifndef PLAYER_H
#define PLAYER_H

#include "Hex.h"

// Forward declarations
class BoardState;
class HexMove;

// Abstract class representing a Player of the game
class Player {
  public:
    // Initialize a Player to a specific color
    Player (Hex::Color color);

    virtual ~Player (void) {};

    // Color getter
    Hex::Color getColor (void);

    // Change to the other color (for pie rule)
    void swapColor (void);

    // Take a turn
    virtual HexMove playTurn (BoardState & board) = 0;

    // Inform the player that they won
    virtual void win (void) = 0;

  protected:
    // This player's color
    Hex::Color playerColor;
};

#endif
