#ifndef WIN_SEARCHER_H
#define WIN_SEARCHER_H

#include "Hex.h"
#include <deque>
#include <map>
#include <memory>

class BoardState;
class BoardNode;
class BoardStraightIterator;
class NeighborVisitor; 

class WinSearcher {
  public:
    // Constructor
    // @param[in]   b   Reference to game board
    WinSearcher (BoardState & b);
  
    // Search for a path of color from one side to the other
    bool findPath (void);

  protected:
    // Board to search over
    BoardState & board;

    // Visitor to use to add nodes to fringe list
    std::shared_ptr<NeighborVisitor> fringeAddVisitor;

    // Initial setup of fringe and goal
    virtual void setup (void) = 0;

    // Visit neighbors to current node
    void visitNeighbors(std::shared_ptr<BoardNode> node);

    // Fringe list of nodes discovered
    std::deque<std::shared_ptr<BoardNode>> fringe;

    // Map of nodes that have already been visited
    std::map<std::shared_ptr<BoardNode>, bool> visited;

    // Map of nodes that are touching the opposite border
    std::map<std::shared_ptr<BoardNode>, bool> goalList;
};

#endif
