#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
  public:
    // Take a turn
    // Print board, ask user for move coords
    HexMove playTurn (BoardState & board);

    // Inform the player that they won
    void win (void);
};

#endif
