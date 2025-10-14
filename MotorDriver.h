#pragma once

#include <Arduino.h>
#include <Bluepad32.h>

class MotorDriver {
public:
  virtual void setup() = 0;
  virtual void set(byte speed, bool forward) = 0;
};
