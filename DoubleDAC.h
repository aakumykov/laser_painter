#define DAC_RESOLUTION_X 4096
#define DAC_RESOLUTION_Y 4096

#include <Adafruit_MCP4725.h>

class DoubleDAC
{
  public:
    void init(){
      this->dac1.begin(DAC1_ADDR);
      this->dac1.begin(DAC2_ADDR);
    }
    void write(int x, int y){
      this->dac1.setVoltage(x*this->stepX, false);
      this->dac2.setVoltage(y*this->stepY, false);
    }
  private:
    static const Adafruit_MCP4725 dac1;
    static const Adafruit_MCP4725 dac2;
    static const float stepX = DAC_RESOLUTION_X / SCREEN_RESOLUTION_X;
    static const float stepY = DAC_RESOLUTION_Y / SCREEN_RESOLUTION_Y;
};
