#include "Laser.h"
#include "DoubleDAC.h"

class Pointer
{
  public:
    Pointer(){
      this->currentX = this->startX;
      this->currentY = this->startY;
    }
  private:
    static const Laser laser;
    static const DoubleDAC dac;
    int currentX, currentY;
    static const int startX = POINTER_START_X;
    static const int startY = POINTER_START_Y;
};

