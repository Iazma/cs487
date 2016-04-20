#ifndef BOARD_ROW_ITERATOR_H
#define BOARD_ROW_ITERATOR_H

#include "BoardStraightIterator.h"

class BoardRowIterator : public BoardStraightIterator {
  public:
    // Constructor
    // @param[in]   start   Node to begin iterating from
    BoardRowIterator (std::shared_ptr<BoardNode> start);

    BoardRowIterator & operator++ (void);

    void operator++ (int);

    BoardRowIterator & operator-- (void);

    void operator-- (int);
};

#endif
