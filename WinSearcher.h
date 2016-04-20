#ifndef WIN_SEARCHER_H
#define WIN_SEARCHER_H

#include "Hex.h"
#include <queue>
#include <map>
#include <memory>

class BoardState;
class BoardNode;

class WinSearcher {
  public:
    // Set what sides we're searching from and what color we're looking for
    WinSearcher (Hex::Color color, BoardState & board);
  
    // Search for a path of color from one side to the other
    bool findPath (void);

  private:
    Hex::Color color_;
    BoardState & board_;

    std::queue<std::shared_ptr<BoardNode>> fringe;
    std::map<std::shared_ptr<BoardNode>, bool> visitedList;
    std::map<std::shared_ptr<BoardNode>, bool> goalList;

    void setupRows (void);
    void setupCols (void);

    bool checkNeighbors (std::shared_ptr<BoardNode> node);
};

#endif
