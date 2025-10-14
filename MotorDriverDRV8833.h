#pragma once

#include "MotorDriver.h"

class MotorDriverDRV8833 : public MotorDriver {
private:
  byte in1_pin;
  byte in2_pin;

public:
  MotorDriverDRV8833(byte in1_pin, byte in2_pin);
  void setup();
  void set(byte speed, bool forward);
};
