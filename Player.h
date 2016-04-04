#ifndef PLAYER_H
#define PLAYER_H

class BoardState;
class HexMove;

class Player {
  public:
    // Take a turn
    virtual HexMove playTurn (BoardState & board) = 0;

    // Inform the player that they won
    virtual void win (void) = 0;
};

#endif
