#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include <queue>

#include "Player.h"

// Class to interact with the neural network to play Hex
class ComputerPlayer : public Player {
  public:
    ComputerPlayer (Hex::Color color);

    // Query the ANN to choose the best move
    HexMove playTurn (BoardState & board);

    // Enact positive reinforcement on the ANN
    void win (void);

    // Enact negative reinforcement on the ANN
    void lose (void);

  protected:
    // History of moves made by this player
    std::queue<HexMove> moveHistory;
};

#endif
