#ifndef NODE_VISITOR_H
#define NODE_VISITOR_H

class BoardNode;

// Abstract class defining a visitor of nodes
class NodeVisitor {
  public:
    virtual void visitBlue (BoardNode & node) = 0;
    virtual void visitRed (BoardNode & node) = 0;
    virtual void visitBlank (BoardNode & node) = 0;
};

#endif
