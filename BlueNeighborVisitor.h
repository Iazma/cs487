#ifndef BLUE_NEIGHBOR_VISITOR_H
#define BLUE_NEIGHBOR_VISITOR_H

#include "NeighborVisitor.h"

#include <deque>
#include <memory>

// Class for adding blue-colored nodes to a deque
class BlueNeighborVisitor : public NeighborVisitor {
  public:
    // Constructor
    // @param[in]   f    Deque to add nodes to
    BlueNeighborVisitor (std::deque<std::shared_ptr<BoardNode>> & f);

    ~BlueNeighborVisitor (void);

    void visitBlue (BoardNode * node);
};

#endif
