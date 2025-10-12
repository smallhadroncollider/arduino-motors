#pragma once

#include <Arduino.h>

class Motor {
private:
  bool flip = false;
  char id;
  byte en_pin;
  byte in1_pin;
  byte in2_pin;

  void logToSerial(byte speed, bool forward);

public:
  static bool log;

  Motor(char id, byte en_pin, byte in1_pin, byte in2_pin);
  void setup();
  void setFlipped();
  void setStandard();
  void update(byte speed, bool forward);
};
