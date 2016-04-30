#ifndef NODE_VISITOR_H
#define NODE_VISITOR_H

class BoardNode;

// Abstract class defining a visitor of nodes
class NodeVisitor {
  public:
    virtual void visitBlue (BoardNode *) {};
    virtual void visitRed (BoardNode *) {};
    virtual void visitBlank (BoardNode *) {};

    virtual void visitDummyBlue (BoardNode *) {};
    virtual void visitDummyRed (BoardNode *) {};
    virtual void visitDummyPurple (BoardNode *) {};
};

#endif
