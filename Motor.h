#include <Arduino.h>

class Motor {
private:
  int en_pin;
  int in1_pin;
  int in2_pin;

public:
  Motor(int en_pin, int in1_pin, int in2_pin);
  void setup();
  void update(int speed, bool forward);
};
