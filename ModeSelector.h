#pragma once

#include "ModeCar.h"
#include "ModeTriggers.h"
#include <Arduino.h>
#include <Bluepad32.h>

struct Modes {
  Mode *car;
  Mode *triggers;
};

class ModeSelector {
private:
  Mode *modePtr;
  Modes modes;
  ControllerPtr &controller;

public:
  ModeSelector(ControllerPtr &controller, Modes modes);
  void update();
};
