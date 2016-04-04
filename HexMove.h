#ifndef HEX_MOVE_H
#define HEX_MOVE_H

// Class to represent a set of x-y coordinates
class HexMove {
  public:
    // Initialize to x and y
    HexMove (int x, int y);

    // Coordinate getters
    int getX (void);
    int getY (void);

  private:
    int x_;
    int y_;
};

#endif
