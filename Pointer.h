#include "Msg.h"
#include "Laser.h"
#include "DoubleDAC.h"
#include <math.h>

class Pointer
{
  public:
    Pointer(){
        Msg::debug("Pointer()");
      this->currentX = POINTER_START_X;
      this->currentY = POINTER_START_Y;
    }
    
    void init(){
        Msg::debug("Pointer.init()");
      this->laser.init();
      this->dac.init();
      this->goTo(this->currentX, this->currentY);
    }
    
    void drawLine(int x1, int y1, int x2, int y2){
      Msg::debug("Pointer.drawLine("+String(x1)+","+String(y1)+","+String(x2)+","+String(y2)+")");
      this->goTo(x1,y1);
      this->lineTo(x2,y2);
    }
    
    void drawPoint(int x, int y){
      Msg::debug("Pointer.drawPoint("+String(x)+","+String(y)+")");
      this->goTo(x,y);
      this->laser.on();
      delayMicroseconds(100);
      this->laser.off();
      delayMicroseconds(50);
    }

  private:
    Laser laser;
    DoubleDAC dac;
    int currentX, currentY;
    
    void goTo(int x, int y){
        Msg::debug("Pointer.goTo("+String(x)+","+String(y)+")");
      int timeout = round(distanceTo(x,y) / POINTER_SPEED);
        Msg::debug("goTo timeout: "+String(timeout));
      this->laser.off();
      this->dac.write(x,y);
      delayMicroseconds(timeout);
    }
    
    void lineTo(int x, int y){
        Msg::debug("Pointer.lineTo("+String(x)+","+String(y)+")");
      int timeout = round(distanceTo(x,y) / POINTER_SPEED);
        Msg::debug("lineTo timeout: "+String(timeout));
      this->laser.on();
      this->dac.write(x,y);
      delayMicroseconds(timeout);
      this->laser.off();
    }
    
    float distance(int x1, int y1, int x2, int y2){
        Msg::debug("Pointer.distance("+String(x1)+","+String(y1)+","+String(x2)+","+String(y2)+")");
      return sqrt( (x2-x1)^2 + (y2-y1)^2 );
    }
    float distanceTo(int x, int y){
        Msg::debug("Pointer.distanceTo("+String(x)+","+String(y)+")");
      // дублирование кода ради ускорения выполнения
      return sqrt( (x - this->currentX)^2 + (y - this->currentY)^2 );
    }

};

