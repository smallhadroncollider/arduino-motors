#pragma once

#include "Motor.h"
#include <Arduino.h>

class Router {
private:
  bool flip = false;
  Motor *motorA;
  Motor *motorB;

public:
  Router(Motor *a, Motor *b);
  void setFlipped();
  void setStandard();
  void setup();
  void updateMotorA(byte speed, bool forward);
  void updateMotorB(byte speed, bool forward);
};
