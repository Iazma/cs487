#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"

// Class representing a person playing the game
class HumanPlayer : public Player {
  public:
    // Initialize a HumanPlayer to a specific color
    HumanPlayer (Hex::Color color);

    virtual ~HumanPlayer (void) {};
    // Take a turn
    // Print board, ask user for move coords
    virtual HexMove playTurn (BoardState & board);

    // Inform the player that they won
    virtual void win (void);
};

#endif
