#pragma once

#include "MotorDriver.h"

class MotorDriverL298N : public MotorDriver {
private:
  byte en_pin;
  byte in1_pin;
  byte in2_pin;

public:
  MotorDriverL298N(byte en_pin, byte in1_pin, byte in2_pin);
  void setup();
  void set(byte speed, bool forward);
};
