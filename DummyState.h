#ifndef DUMMY_STATE_H
#define DUMMY_STATE_H

#include "NodeState.h"

// Dummy state to use instead for edge nodes instead of nullptrs
class DummyState : public NodeState {
  public:
    DummyState (void);
    ~DummyState (void);

};

class DummyRed : public DummyState {
  public:
    DummyRed (void);
    ~DummyRed (void);

    void accept (BoardNode & n, NodeVisitor & v);
};

class DummyBlue : public DummyState {
  public:
    DummyBlue (void);
    ~DummyBlue (void);

    void accept (BoardNode & n, NodeVisitor & v);
};

class DummyPurple : public DummyState {
  public:
    DummyPurple (void);
    ~DummyPurple (void);

    void accept (BoardNode & n, NodeVisitor & v);
};

#endif
