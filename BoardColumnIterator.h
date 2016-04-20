#ifndef BOARD_COLUMN_ITERATOR_H
#define BOARD_COLUMN_ITERATOR_H

#include <memory>

// Forward declarations
class BoardNode;

// Class for iterating down the column of the game board
class BoardColumnIterator {
  public:
    // Constructor
    // @param[in]   start   Node to begin iterating from
    BoardColumnIterator (std::shared_ptr<BoardNode> start);

    // Returns true if iterator out of bounds
    bool finished (void);

    // Pre-increment overload: Point to next node in column
    BoardColumnIterator & operator++ (void);

    // Post-increment overload: Point to next node in column
    BoardColumnIterator operator++ (int);

    // Pre-decrement overload: Point to previous node in column
    BoardColumnIterator & operator-- (void);

    // Post-decrement overload: Point to previous node in column
    BoardColumnIterator operator-- (int);

    // Dereference operator 
    BoardNode & operator* (void);

    // Arrow operator
    BoardNode * operator-> (void);

    // Comparison operators
    friend bool operator== (const BoardColumnIterator & lhs, const BoardColumnIterator & rhs);

    friend bool operator!= (const BoardColumnIterator & lhs, const BoardColumnIterator & rhs);

    // Assignment
    const BoardColumnIterator & operator= (const BoardColumnIterator & rhs);

  private:
    std::shared_ptr<BoardNode> current;
};
#endif
