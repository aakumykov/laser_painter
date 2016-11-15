class Laser {
  public:
    void init(){
        Msg::debug("Laser.init()");
      pinMode(LASER_PIN, OUTPUT);
    }
    void on(){
        Msg::debug("Laser.on()");
      digitalWrite(LASER_PIN, HIGH);
      delayMicroseconds(5);
    }
    void off(){
        Msg::debug("Laser.off()");
      digitalWrite(LASER_PIN,LOW);
      delayMicroseconds(5);
    }
};

