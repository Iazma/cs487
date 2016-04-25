#ifndef RED_WIN_SEARCHER_H
#define RED_WIN_SEARCHER_H

#include "WinSearcher.h"

// Class to check if Red won the game
class RedWinSearcher : public WinSearcher {
  public:
    // Constructor
    // @param[in]   b   Reference to game board
    RedWinSearcher (BoardState & b);

  protected:
    // Set up the fringe and goal list based up top/bottom sides
    void setup (void);
};

#endif
