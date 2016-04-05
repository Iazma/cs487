#include "HexMove.h"

HexMove::HexMove (int x, int y)
  : x_(x)
   ,y_(y)
{};

int HexMove::getX (void) {
  return x_;
}

int HexMove::getY (void) {
  return y_;
}
