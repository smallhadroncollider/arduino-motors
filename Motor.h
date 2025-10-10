#pragma once

#include <Arduino.h>

class Motor {
private:
  bool flip = false;
  byte en_pin;
  byte in1_pin;
  byte in2_pin;

public:
  Motor(byte en_pin, byte in1_pin, byte in2_pin);
  void setup();
  void setFlipped();
  void setStandard();
  void update(byte speed, bool forward);
};
