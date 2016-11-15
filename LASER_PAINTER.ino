#define LASER_PIN 5
#define DAC1_ADDR 0x60
#define DAC2_ADDR 0x61
#define SCREEN_RESOLUTION_X 2048
#define SCREEN_RESOLUTION_Y 2048
#define POINTER_START_X 0
#define POINTER_START_Y 0

#include "Pointer.h"

Pointer pointer;

void setup() {
  pointer.init();
}

void loop() {

}
