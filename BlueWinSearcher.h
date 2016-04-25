#ifndef BLUE_WIN_SEARCHER_H
#define BLUE_WIN_SEARCHER_H

#include "WinSearcher.h"

// Class to check if Blue won the game
class BlueWinSearcher : public WinSearcher {
  public:
    // Constructor
    // @param[in]   b   Reference to game board
    BlueWinSearcher (BoardState & b);

  protected:
    // Set up fringe and goal list based on left/right sides
    void setup (void);
};

#endif
