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
      Msg::debug("---------------- Pointer.init() start ----------------");
      
      this->laser.init();
      delay(100);
      
      this->dac.init();
      delay(100);
      
      this->goTo(this->currentX, this->currentY);
      delay(100);
      
      for (byte i=0; i<3; i++){
        this->laser.on(); delay(300); 
        this->laser.off(); delay(300);
      }

      Msg::debug("---------------- Pointer.init() finish ----------------");
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
      
      double timeout = round(distanceTo(x,y) / POINTER_SPEED);
        Msg::debug("goTo timeout: "+String(timeout));

      this->currentX = x;
      this->currentY = y;
      
      this->laser.off();
      this->dac.write(x,y);
      delay(timeout);
    }
    
    void lineTo(int x, int y){
      Msg::debug("Pointer.lineTo("+String(x)+","+String(y)+")");
      
      double timeout = round(distanceTo(x,y) / POINTER_SPEED);
        Msg::debug("lineTo timeout: "+String(timeout));

      this->currentX = x;
      this->currentY = y;
      
      this->laser.on();
      this->dac.write(x,y);
      delay(timeout);
      this->laser.off();
    }
    
    float distance(int x1, int y1, int x2, int y2){
      Msg::debug("Pointer.distance("+String(x1)+","+String(y1)+","+String(x2)+","+String(y2)+")");
      float dist = sqrt( pow((x2-x1),2) + pow((y2-y1),2) );
        //Msg::debug("distance="+String(dist));
      return dist;
    }
    float distanceTo(int x, int y){
      // дублирование кода ради ускорения выполнения
      Msg::debug("Pointer.distanceTo("+String(x)+","+String(y)+")");
      float dist = sqrt( pow((x - this->currentX),2) + pow((y - this->currentY),2) );
        //Msg::debug("distance="+String(dist));
      return dist;
    }

};

