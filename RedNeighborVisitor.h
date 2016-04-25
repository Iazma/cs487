#ifndef RED_NEIGHBOR_VISITOR_H
#define RED_NEIGHBOR_VISITOR_H

#include "NeighborVisitor.h"

#include <deque>
#include <memory>

// Class for adding red-colored nodes to a deque
class RedNeighborVisitor : public NeighborVisitor {
  public:
    // Constructor
    // @param[in]   f   Deque to add nodes to
    RedNeighborVisitor (std::deque<std::shared_ptr<BoardNode>> & f);

    ~RedNeighborVisitor (void);

    void visitBlue (BoardNode & node);
    void visitRed (BoardNode & node);
    void visitBlank (BoardNode & node);
};

#endif
