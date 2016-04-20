#ifndef HEX_H
#define HEX_H

#include <string>
// Provides namespace for the possible node colors

namespace Hex {
  enum Color { BLANK, BLUE, RED };

  class ColorState {
    public:
      virtual Color getColor (void) = 0;
      virtual std::string print (void) = 0;
  };

  class BlankState : public ColorState {
    public:
      Color getColor (void);
      std::string print (void);
  };

  class BlueState : public ColorState {
    public:
      Color getColor (void);
      std::string print (void);
  };

  class RedState : public ColorState {
    public:
      Color getColor (void);
      std::string print (void);
  };
}

#endif
