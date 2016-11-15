#include "Laser.h"
#include "DoubleDAC.h"

class Pointer
{
  public:
    Pointer(){
      this->currentX = POINTER_START_X;
      this->currentY = POINTER_START_Y;
    }
    void init(){
      this->laser.init();
      this->dac.init();
    }
  private:
    Laser laser;
    DoubleDAC dac;
    int currentX, currentY;
};

