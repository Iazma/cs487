#ifndef NEIGHBOR_VISITOR_H
#define NEIGHBOR_VISITOR_H

#include "NodeVisitor.h"

#include <deque>
#include <memory>

// Class for adding a node to a deque
class NeighborVisitor : public NodeVisitor {
  public:
    // Constructor
    // @param[in]   f   Deque to add nodes to
    NeighborVisitor (std::deque<std::shared_ptr<BoardNode>> & f);

    virtual ~NeighborVisitor (void);

  protected:
    std::deque<std::shared_ptr<BoardNode>> & fringe;
};

#endif
