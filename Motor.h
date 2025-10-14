#pragma once

#include "MotorDriver.h"
#include <Arduino.h>

class Motor {
private:
  bool flip = false;
  char id;
  MotorDriver &driver;

  void logToSerial(byte speed, bool forward);

public:
  static bool log;

  Motor(char id, MotorDriver &driver);
  void setFlipped();
  void setStandard();
  void update(byte speed, bool forward);
};
