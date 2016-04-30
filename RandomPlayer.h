#ifndef RANDOM_PLAYER_H
#define RANDOM_PLAYER_H

#include "Player.h"

// Class representing a computer player that plays randomly
class RandomPlayer : public Player {
  public:
    RandomPlayer (std::shared_ptr<NodeState> c);

    ~RandomPlayer (void) {};

    // Pick random board spaces until a legal move is found, return it
    HexMove playTurn (BoardState & board);

    // No-op, random player don't care
    void win (void);

    // No-op, random player don't care
    void lose (void);
};

#endif
