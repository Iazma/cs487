#ifndef BOARD_STRAIGHT_ITERATOR_H
#define BOARD_STRAIGHT_ITERATOR_H

#include <memory>

// Forward declarations
class BoardNode;

// Abstract class for iterating in a straight line across the board
class BoardStraightIterator {
  public:
    // Constructor
    // @param[in]   start   Node to begin iterating from
    BoardStraightIterator (std::shared_ptr<BoardNode> start);

    // Returns true if iterator out of bounds
    bool finished (void);

    // Pre-increment overload: Point to next node in column
    virtual BoardStraightIterator & operator++ (void) = 0;

    // Post-increment overload: Point to next node in column
    virtual void operator++ (int) = 0;

    // Pre-decrement overload: Point to previous node in column
    virtual BoardStraightIterator & operator-- (void) = 0;

    // Post-decrement overload: Point to previous node in column
    virtual void operator-- (int) = 0;

    // Dereference operator 
    BoardNode & operator* (void);

    // Arrow operator
    BoardNode * operator-> (void);

    // Comparison operators
    friend bool operator== (const BoardStraightIterator & lhs, const BoardStraightIterator & rhs);

    friend bool operator!= (const BoardStraightIterator & lhs, const BoardStraightIterator & rhs);

    // Assignment
    const BoardStraightIterator & operator= (const BoardStraightIterator & rhs);

  protected:
    std::shared_ptr<BoardNode> current;
};
#endif
