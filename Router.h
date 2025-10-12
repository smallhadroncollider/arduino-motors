#pragma once

#include "Motor.h"
#include <Arduino.h>
#include <Bluepad32.h>

class Router {
private:
  bool flip = false;
  Motor *motorA;
  Motor *motorB;

  void setFlipped();
  void setStandard();
  void logMotor(char motor, byte speed, bool forward);

public:
  static bool log;

  Router(Motor *a, Motor *b);
  void handleFlip(ControllerPtr &controller);
  void setup();
  void reset();
  void updateMotorA(byte speed, bool forward);
  void updateMotorB(byte speed, bool forward);
};
