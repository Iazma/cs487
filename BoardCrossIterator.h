#ifndef BOARD_CROSS_ITERATOR_H
#define BOARD_CROSS_ITERATOR_H

#include "BoardStraightIterator.h"

// Class to iterate from up-right to down-left or vice versa
class BoardCrossIterator : public BoardStraightIterator {
  public:
    BoardCrossIterator (std::shared_ptr<BoardNode> start);

    ~BoardCrossIterator (void);

    BoardCrossIterator & operator++ (void);

    void operator++ (int);

    BoardCrossIterator & operator-- (void);

    void operator-- (int);
};

#endif
