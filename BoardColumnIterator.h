#ifndef BOARD_COLUMN_ITERATOR_H
#define BOARD_COLUMN_ITERATOR_H

#include "BoardStraightIterator.h"

// Class to iterate over a column of BoardNodes
class BoardColumnIterator : public BoardStraightIterator {
  public:
    // Constructor
    // @param[in]   start   Node to start iterating from
    BoardColumnIterator (std::shared_ptr<BoardNode> start);

    BoardColumnIterator & operator++ (void);

    void operator++ (int);

    BoardColumnIterator & operator-- (void);

    void operator-- (int);

};

#endif
