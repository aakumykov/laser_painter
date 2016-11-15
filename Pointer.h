#include "Laser.h"
#include "DoubleDAC.h"
#include <math.h>

class Pointer
{
  public:
    Pointer(){
      this->currentX = POINTER_START_X;
      this->currentY = POINTER_START_Y;
    }
    void init(){
        Serial.writeln("Pointer.init()");
      this->laser.init();
      this->dac.init();
      this->goTo(this->currentX, this->currentY);
    }
    void goTo(int x, int y){
      int timeout = round(distanceTo(x,y) / POINTER_SPEED);
        Serial.writeln("lineTo timeout: "+String(timeout));
      this->laser.off();
      this->dac.write(x,y);
      delayMicroseconds(timeout);
    }
    void lineTo(int x, int y){
      int timeout = round(distanceTo(x,y) / POINTER_SPEED);
        Serial.writeln("lineTo timeout: "+String(timeout));
      this->laser.on();
      this.dac.write(x,y);
      delayMicroseconds(timeout);
      this->laser.off();
    }
  private:
    Laser laser;
    DoubleDAC dac;
    int currentX, currentY;
    float distance(int x1, int y1, int x2, int y2){
      return sqrt( (x2-x1)^2 + (y2-y1)^2 );
    }
    float distanceTo(int x, int y){
      // дублирование кода ради ускорения выполнения
      return sqrt( (x - this->currentX)^2 + (y - this->currentY)^2 );
    }
};

