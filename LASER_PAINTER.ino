#define LASER_PIN 5
#define DAC1_ADDR 0x60
#define DAC2_ADDR 0x61
#define SCREEN_RESOLUTION_X 2048
#define SCREEN_RESOLUTION_Y 2048
#define POINTER_START_X 0
#define POINTER_START_Y 0
#define POINTER_SPEED 50 //точек (каких?) в микромекунду. Нужно калибровать или подбирать...

#include "Pointer.h"

Pointer pointer;

void setup() {
  Serial.begin(230400);
  pointer.init();
}

void loop() {
  pointer.drawLine(0,0,0,1000);
  //delay(1000);
}
