class Laser {
  public:
    void init(){
        Serial.writeln("Laser.init()");
      pinMode(LASER_PIN, OUTPUT);
    }
    void on(){
      digitalWrite(LASER_PIN, HIGH);
    }
    void off(){
      digitalWrite(LASER_PIN,LOW);
    }
};

